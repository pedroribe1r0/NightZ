#include "Character.h"

namespace Entities {
	namespace Characters {
		Character::Character(Math::CoordF pos, Math::CoordF size, ID id, Math::CoordF speed, int hp, int stamina) : MovingEntity(pos, size, id, speed), hp(hp), stamina(stamina){}
		Character::~Character() {}
		void Character::takeDamage(int damage) {
			int newLife = hp - damage;
			if (newLife >= 0)
				hp = newLife;
			else
				hp = 0;
		}
	}
}