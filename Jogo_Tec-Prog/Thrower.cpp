#include "Thrower.h"
#include "Projectile.h"
#include "EntitiesList.h"

namespace Entities {
	namespace Characters {
		Thrower::Thrower(Math::CoordF pos, EntitiesList* list) : Enemy(pos,Math::CoordF(THROWER_SIZE_X, THROWER_SIZE_Y),thrower, THROWER_HP), isAttacking(false), attackTime(0) {
			p = new Projectile(this);
			list->setData(p);
			meleeDamage = THROWER_DAMAGE;
			setTextures();
		}
		Thrower::~Thrower() {
		}
		void Thrower::damage() {
			isAttacking = true;
		}
		void Thrower::setTextures() {
			sprite = new GraphicalElements::Animation(body, Math::CoordF(2.8f, 2.8f));
			sprite->addNewAnimation(GraphicalElements::Animation_ID::walk, "SpittingZombie - Walk.png", 10);
			sprite->addNewAnimation(GraphicalElements::Animation_ID::dmg, "SpittingZombie - Hit.png", 5);
			sprite->addNewAnimation(GraphicalElements::Animation_ID::attack, "SpittingZombie - Attack.png", 19);
			sprite->addNewAnimation(GraphicalElements::Animation_ID::idle, "SpittingZombie - Idle.png", 20);
			sprite->addNewAnimation(GraphicalElements::Animation_ID::death, "SpittingZombie - Death.png", 19);
		}
		void Thrower::takeDistance(Player* p) {
			if (p->getPosition().x > position.x) {
				move(true);
			}
			else {
				move(false);
			}
		}
		void Thrower::update(float dt) {
			stop();

			Player* near = nullptr;
			if (pPlayer1 && pPlayer2) {
				near = pPlayer2;
				if (fabs(position.x - pPlayer1->getPosition().x) < fabs(position.x - pPlayer2->getPosition().x)) { //identificar o player mais proximo
					near = pPlayer1;
				}
			}
			else if (pPlayer1) {
				near = pPlayer1;
			}
			else if (pPlayer2) {
				near = pPlayer2;
			}
			if (near) {
				float distance = position.x - near->getPosition().x;
				facingLeft = false;
				if (distance > 0) { //verificar pra qual lado atirar, mesmo que nao precise se mover
					facingLeft = true;
				}
				if (fabs(distance) > 150 && fabs(distance) < 300) {//verificar se esta dentro do range e se o cooldown esta maior q o tempo estipulado
					if (!isAttacking && !p->getIsActive()) {
						damage();
					}
				}
				else if (fabs(distance) < 191 && !isAttacking) {
					takeDistance(near);
				}
					
				else if (fabs(distance) >= 199 && !isAttacking) //verificar se o motivo do loop foi nao ter cooldown ou estar longe
					chasePlayer(near);
			}
			if (isAttacking) {
				stop();
				sprite->update(GraphicalElements::Animation_ID::attack, facingLeft, position, dt);
				attackTime += dt;
				if (attackTime >= 0.9f && attackTime < 0.95f) {
					p->shoot(facingLeft);
				}
				else if (attackTime >= THROWER_ATTACK_TIME) {
					isAttacking = false;
					attackTime = 0;
				}
			}
			else if (takingDamage) {
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
			
			if (isMoving) {
				if (facingLeft)
					speed.x = -THROWER_SPEED;
				else
					speed.x = THROWER_SPEED;
			}
			else {
				speed.x = 0;
			}
			position.x += speed.x * dt;
			position.y += speed.y * dt;
		}
		string Thrower::save() {
			string line = "";
			line += to_string(static_cast<int>(id)) + ' ';
			line += to_string(position.x) + ' ';
			line += to_string(position.y) + ' ';
			line += to_string(hp) + ' ';
			return line;
		}
	}
}
