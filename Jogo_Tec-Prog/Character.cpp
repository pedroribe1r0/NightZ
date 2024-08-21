#include "Character.h"

namespace Entities {
	namespace Characters {
		Character::Character(Math::CoordF pos, Math::CoordF size, ID id, int hp, int stamina) : 
			MovingEntity(pos, size, id), 
			hp(hp), 
			stamina(stamina),
			canJump(false){}

		Character::~Character() {}
		void Character::takeDamage(int damage) {
			int newLife = hp - damage;
			if (newLife >= 0)
				hp = newLife;
			else
				hp = 0;
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

		void Character::execute(float dt) {
			if (speed.y <= 500.0) {
				speed.y += GRAVIDADE * dt;
			}
			update(dt);
		}

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
					position.y += intersection.y;
				}
				else 
					position.y -= intersection.y;
			}
		}
	}
}