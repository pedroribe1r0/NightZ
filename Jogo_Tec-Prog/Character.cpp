#include "Character.h"

namespace Entities {
	namespace Characters {
		Character::Character(Math::CoordF pos, Math::CoordF size, ID id, float hp) : 
			MovingEntity(pos, size, id), 
			hp(hp),
			canJump(false),
			isAlive(true),
			timeDamageAnimation(0),
			takingDamage(false){}

		Character::~Character() {}
		void Character::takeDamage(float damage) {
			takingDamage = true;
			float newLife = hp - damage;
			if (newLife > 0)
				hp = newLife;
			else {
				hp = 0;
				isAlive = false;
			}
		}
		void Character::jump() {
			if (canJump) {
				canJump = false;
				speed.y = JUMP;
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
			if (speed.y <= 800.0) {
				speed.y += GRAVIDADE * dt;
			}
			update(dt);
			//body->setPosition(sf::Vector2f(position.x, position.y));
		}//corrigir double jump no ar

		void Character::moveOnCollision(Entity* ent, Math::CoordF intersection) {
			Math::CoordF otherPos = ent->getPosition();
			if (intersection.x > intersection.y) { // Colision on x direction
				if (position.x < otherPos.x)
					position.x += intersection.x;
				else
					position.x -= intersection.x;	
			}

			else { // Colision on y direction
				
				if (position.y < otherPos.y) {
					canJump = true;
					speed.y = 0;
					position.y += intersection.y;
				}
				else 
					position.y -= intersection.y;
			}
		}
	}
}