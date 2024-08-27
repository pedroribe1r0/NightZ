#include "Boss.h"

namespace Entities {
	namespace Characters {
		Boss::Boss(Math::CoordF pos, Player* p1, Player* p2) : Enemy(pos, Math::CoordF(BOSS_SIZE_X, BOSS_SIZE_Y), enemy, BOSS_HP, p1, p2){
			meleeDamage = BOSS_DAMAGE;
			attackRange = BOSS_ATTACK_RANGE;
			attackDamage = BOSS_ATTACK_DAMAGE;
			cooldownTimer = 0;
			attackTime = ATTACK_TIME;
			isAttacking = false;
		}
		Boss::~Boss() {

		}
		void Boss::collide(Entity* ent, Math::CoordF intersection, float dt) {
			switch (ent->getID()) {
			case ID::obstacle:
				moveOnCollision(ent, intersection);
				break;
			case enemy:
				moveOnCollision(ent, intersection);
				break;
			case player: {
				Player* p = dynamic_cast<Player*>(ent);
				if (p) {
					p->takeDamage(meleeDamage * dt);
				}
				moveOnCollision(ent, intersection);
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
				body->setFillColor(sf::Color::Red);
				if (attackTime >= ATTACK_TIME) {
					isAttacking = false;
					attack();
					cooldownTimer = 0;
				}
			}
			else {
				cooldownTimer += dt;
				if (cooldownTimer >= BOSS_COOLDOWN) {
					isAttacking = true;
					attackTime = 0;
				}
				if (pPlayer1 && pPlayer2) {
					if (fabs(position.x - pPlayer1->getPosition().x) < fabs(position.x - pPlayer2->getPosition().x)) {
						chasePlayer(pPlayer1);
					}
					else {
						chasePlayer(pPlayer2);
					}
				}
				else if (pPlayer1) {
					chasePlayer(pPlayer1);

				}
				else if (pPlayer2) {
					chasePlayer(pPlayer2);
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
		}
		void Boss::attack() {
			//animacao
			if (pPlayer1) {
				float distance1 = 0;
				if (facingLeft) {
					distance1 = position.x - pPlayer1->getPosition().x - size.x / 2 - pPlayer1->getSize().x / 2;
				}
				else {
					distance1 = position.x - pPlayer1->getPosition().x + size.x / 2 + pPlayer1->getSize().x / 2;
				}
				if (pPlayer1->getPosition().y + pPlayer1->getSize().y / 2 == position.y + size.y / 2) {
					if ((facingLeft && distance1 > 0) || (!facingLeft && distance1 <= 0)) {
						cout << fabs(distance1) << endl;
						if (fabs(distance1) <= attackRange) {
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
				if (pPlayer2->getPosition().y + pPlayer2->getSize().y / 2 == position.y + size.y / 2) {
					if ((facingLeft && distance2 > 0) || (!facingLeft && distance2 < 0)) {
						if (fabs(distance2) <= attackRange) {
							paralizePlayer(pPlayer2);
							pPlayer2->takeDamage(attackDamage);
						}
					}
				}
			}
		}
		void Boss::paralizePlayer(Player* p) {
			if (p) {
				p->setCanMove(false);
				p->resetParalizeTime();
			}
		}
	}
}
