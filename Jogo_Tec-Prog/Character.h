#pragma once
#include "MovingEntity.h"

namespace Entities {
	namespace Characters {
		class Character : public MovingEntity
		{
		protected:
			int hp;
			int stamina;
			/*To do*/
		public:
			Character(Math::CoordF pos = Math::CoordF(0, 0), Math::CoordF size = Math::CoordF(0, 0), ID id = ID::empty, Math::CoordF speed = Math::CoordF(0, 0), int hp = 0, int stamina = 0);
			virtual ~Character();
			void takeDamadge(int damadge);
			virtual void attack() = 0;
			virtual void update(float dt) = 0;
			virtual void render() = 0;
		};
	}
}

