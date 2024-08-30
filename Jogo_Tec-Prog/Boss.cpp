#include "Boss.h"

namespace Entities {
	namespace Characters {
		Boss::Boss(Math::CoordF pos) : Enemy(pos, Math::CoordF(BOSS_SIZE_X, BOSS_SIZE_Y), boss, BOSS_HP){
			meleeDamage = BOSS_DAMAGE;
			attackRange = BOSS_ATTACK_RANGE;
			attackDamage = BOSS_ATTACK_DAMAGE;
			cooldownTimer = BOSS_COOLDOWN;
			attackTime = 0;
			isAttacking = false;
			canAttack = true;
			setTextures();
		}
		Boss::~Boss() {

		}
		void Boss::collide(Entity* ent, Math::CoordF intersection, float dt) {
			switch (ent->getID()) {
			case ID::obstacle:
				moveOnCollision(ent, intersection);
				break;
			case enemy:
				//moveOnCollision(ent, intersection);
				break;
			case boss:
				moveOnCollision(ent, intersection);
				break;
			case player: {
				Player* p = dynamic_cast<Player*>(ent);
				if (p && !isDying) {
					p->takeDamage(meleeDamage * dt);
				}
				//moveOnCollision(ent, intersection);
				break;
			}
			default:
				break;
			}
		}
		void Boss::update(float dt) {
			stop();
			srand(time(NULL));
			if (isAttacking) {
				attackTime += dt;
				stop();
				sprite->update(GraphicalElements::Animation_ID::attack, facingLeft, position, dt);
				if (attackTime >= HIT_TIME && attackTime < HIT_TIME + 0.5 && canAttack) {
					damage();
					canAttack = false;
				}
				if (attackTime >= ATTACK_TIME) {
					isAttacking = false;
					canAttack = true;
					cooldownTimer = 0;
					attackTime = 0;
				}
			}
			else {
				cooldownTimer += dt;
				if (pPlayer1 && pPlayer2) {
					if (fabs(position.x - pPlayer1->getPosition().x) < fabs(position.x - pPlayer2->getPosition().x)) {
						if (cooldownTimer >= BOSS_COOLDOWN && fabs(position.x - pPlayer1->getPosition().x) <= (BOSS_ATTACK_RANGE + pPlayer1->getSize().x)) {
							isAttacking = true;
						}
						chasePlayer(pPlayer1);
					}
					else {
						if (cooldownTimer >= BOSS_COOLDOWN && fabs(position.x - pPlayer2->getPosition().x) <= (BOSS_ATTACK_RANGE + pPlayer2->getSize().x)) {
							isAttacking = true;
						}
						chasePlayer(pPlayer2);
					}
				}
				else if (pPlayer1) {
					chasePlayer(pPlayer1);
					if (cooldownTimer >= BOSS_COOLDOWN && fabs(position.x - pPlayer1->getPosition().x) <= (BOSS_ATTACK_RANGE + size.x + pPlayer1->getSize().x)) {
						isAttacking = true;
					}
				}
				else if (pPlayer2) {
					chasePlayer(pPlayer2);
					if (cooldownTimer >= BOSS_COOLDOWN && fabs(position.x - pPlayer2->getPosition().x) <= (BOSS_ATTACK_RANGE + size.x + pPlayer2->getSize().x)) {
						isAttacking = true;
					}
				}
				if (takingDamage) {
					sprite->update(GraphicalElements::Animation_ID::dmg, facingLeft, position, dt);
					timeDamageAnimation += dt;
					if (timeDamageAnimation >= TIME_DMG_ANIMATION) {
						timeDamageAnimation = 0;
						takingDamage = false;
					}
				}
				else if (isMoving) {
					sprite->update(GraphicalElements::Animation_ID::walk, facingLeft, position, dt);
				}
				else {
					sprite->update(GraphicalElements::Animation_ID::idle, facingLeft, position, dt);
				}
			}
			if (isMoving) {
				if (facingLeft)
					speed.x = -BOSS_SPEED;
				else
					speed.x = BOSS_SPEED;
			}
			else {
				speed.x = 0;
			}
			position.x += speed.x * dt;
			position.y += speed.y * dt;

		}
		void Boss::setTextures() {
			sprite = new GraphicalElements::Animation(body, Math::CoordF(4, 4));
			sprite->addNewAnimation(GraphicalElements::Animation_ID::walk, "BigZombie - Walk.png", 13);
			sprite->addNewAnimation(GraphicalElements::Animation_ID::dmg, "BigZombie - Hit.png", 5);
			sprite->addNewAnimation(GraphicalElements::Animation_ID::attack, "BigZombie - Attack.png", 22);
			sprite->addNewAnimation(GraphicalElements::Animation_ID::idle, "BigZombie - Idle.png", 13);
			sprite->addNewAnimation(GraphicalElements::Animation_ID::death, "BigZombie - Death.png", 16);
		}
		void Boss::damage() {
			if (pPlayer1) {
				float distance1 = 0;
				if (facingLeft) {
					distance1 = position.x - pPlayer1->getPosition().x - size.x / 2 - pPlayer1->getSize().x / 2;
				}
				else {
					distance1 = position.x - pPlayer1->getPosition().x + size.x / 2 + pPlayer1->getSize().x / 2;
				}
				float dy = pPlayer1->getPosition().y + pPlayer1->getSize().y / 2 - (position.y + size.y/2);
				if (dy < 80 && dy > -80) {
					if ((facingLeft && distance1 > 0) || (!facingLeft && distance1 <= 0)) {
						if (fabs(distance1) <= attackRange) {
							pPlayer1->jump();
							paralizePlayer(pPlayer1);
							pPlayer1->takeDamage(attackDamage);
						}
					}
				}
			}
			if (pPlayer2) {
				float distance2 = 0;
				if (facingLeft) {
					distance2 = position.x - pPlayer2->getPosition().x - size.x / 2 - pPlayer2->getSize().x / 2;
				}
				else {
					distance2 = position.x - pPlayer2->getPosition().x + size.x / 2 + pPlayer2->getSize().x / 2;
				}
				float dy = pPlayer2->getPosition().y + pPlayer2->getSize().y / 2 - (position.y + size.y / 2);
				if (dy < 80 && dy > -80) {
					if ((facingLeft && distance2 > 0) || (!facingLeft && distance2 < 0)) {
						if (fabs(distance2) <= attackRange) {
							paralizePlayer(pPlayer2);
							pPlayer2->jump();
							pPlayer2->takeDamage(attackDamage);
						}
					}
				}	
			}
		}
		void Boss::paralizePlayer(Player* p) {
			if (p) {
				p->setIsParalized();
			}
		}
	}
}
