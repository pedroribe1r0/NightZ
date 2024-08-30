#include "Character.h"

namespace Entities {
	namespace Characters {
		Character::Character(Math::CoordF pos, Math::CoordF size, ID id, float hp) : 
			MovingEntity(pos, size, id), 
			hp(hp),
			canJump(false),
			isAlive(true),
			timeDamageAnimation(0),
			isDying(false),
			deathTimeCounter(0),
			takingDamage(false){}

		Character::~Character() {}
		void Character::takeDamage(float damage) {
			takingDamage = true;
			float newLife = hp - damage;
			if (newLife > 0)
				hp = newLife;
			else {
				hp = 0;
				isDying = true;
				size = Math::CoordF(0, 0);
			}
		}
		void Character::jump(float mult) {
			if (mult < 0)
				mult = 1;
			if (canJump) {
				canJump = false;
				speed.y = JUMP * mult;
			}
		}
		void Character::setCanJump(bool cj) {
			canJump = cj;
		}
		bool Character::getCanJump() const{
			return canJump;
		}

		bool Character::getIsAlive() const {
			return isAlive;
		}

		void Character::execute(float dt) {
			if (isDying) {
				deathTimeCounter += dt;
				sprite->update(GraphicalElements::Animation_ID::death, facingLeft, position, dt);
				if (deathTimeCounter >= DEATH_TIME)
					isAlive = false;
			}
			else {
				if (speed.y <= 800.0) {
					speed.y += GRAVIDADE * dt;
				}
				update(dt);
			}
		}//corrigir double jump no ar

		void Character::moveOnCollision(Entity* ent, Math::CoordF intersection) {
			if (!isDying) {
				Math::CoordF otherPos = ent->getPosition();
				if (intersection.x > intersection.y) { // Colision on x direction
					if (position.x < otherPos.x)
						position.x += intersection.x;
					else
						position.x -= intersection.x;
				}

				else { // Colision on y direction

					if (position.y < otherPos.y) {
						position.y += intersection.y;
						if (speed.y > 0) {
							canJump = true;
							speed = 0;
						}
							
					}
					else
						position.y -= intersection.y;
				}
			}
		}
		float Character::getSpeedY() const {
			return speed.y;
		}
	}
}