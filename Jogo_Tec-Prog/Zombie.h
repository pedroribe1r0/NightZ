#pragma once
#include "Enemy.h"

namespace Entities {
	namespace Characters {
		class Animation;
		#define ZOMBIE_SIZE_X 15.0f
		#define ZOMBIE_SIZE_Y 85.0f
		#define ZOMBIE_HP 100.0f
		#define ZOMBIE_DAMAGE 20.0f
		#define ZOMBIE_SPEED 80.0f
		class Zombie : public Enemy
		{
		public:
			Zombie(Math::CoordF pos = Math::CoordF(0, 0));
			~Zombie();
			void attack();
			void update(float dt);
			void collide(Entity* ent, Math::CoordF intersection, float dt);
			void setTextures();
		};
	}
}

