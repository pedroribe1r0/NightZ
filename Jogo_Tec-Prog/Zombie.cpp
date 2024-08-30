#include "Zombie.h"

namespace Entities {
	namespace Characters {

		Zombie::Zombie(Math::CoordF pos) : Enemy(pos, Math::CoordF(ZOMBIE_SIZE_X, ZOMBIE_SIZE_Y), enemy, ZOMBIE_HP){
			meleeDamage = ZOMBIE_DAMAGE;
			setTextures();
			zombieSpeed = ZOMBIE_SPEED;
		}
		Zombie::~Zombie() {

		}
		void Zombie::damage() {

		}
		void Zombie::setTextures() {
			sprite = new GraphicalElements::Animation(body, Math::CoordF(2.8f, 2.8f));
			sprite->addNewAnimation(GraphicalElements::Animation_ID::walk, "Zombie _Walk.png", 9);
			sprite->addNewAnimation(GraphicalElements::Animation_ID::dmg, "Zombie _Hit.png", 4);
			sprite->addNewAnimation(GraphicalElements::Animation_ID::attack, "Zombie_Attack.png", 17);
			sprite->addNewAnimation(GraphicalElements::Animation_ID::death, "Zombie_Death.png", 15);
			sprite->addNewAnimation(GraphicalElements::Animation_ID::idle, "Zombie _Idle.png", 9);
		}
		void Zombie::increaseSpeed(float speed) {
			zombieSpeed = speed;
		}
		void Zombie::update(float dt) {
			stop();
			srand(time(NULL));
			if (rand() % 5 == 0) {
				jump();
			}
			increaseSpeed(ZOMBIE_SPEED + (100 - hp));
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
			if (isMoving) {
				if (facingLeft)
					speed.x = -zombieSpeed;
				else
					speed.x = zombieSpeed;
			}
			else {
				speed.x = 0;
			}
			position.x += speed.x * dt;
			position.y += speed.y * dt;

			if (takingDamage) {
				sprite->update(GraphicalElements::Animation_ID::dmg, facingLeft, position, dt);
				timeDamageAnimation += dt;
				if (timeDamageAnimation >= TIME_DMG_ANIMATION) {
					timeDamageAnimation = 0;
					takingDamage = false;
				}
			}
			else if (zombieSpeed > ZOMBIE_SPEED) {
				sprite->update(GraphicalElements::Animation_ID::attack, facingLeft, position, dt);
			}
			else if (isMoving) {
				sprite->update(GraphicalElements::Animation_ID::walk, facingLeft, position, dt);
			}
			else
				sprite->update(GraphicalElements::Animation_ID::idle, facingLeft, position, dt);
		}
	}
}
