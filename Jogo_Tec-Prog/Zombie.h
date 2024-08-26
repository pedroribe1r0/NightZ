#pragma once
#include "Enemy.h"

namespace Entities {
	namespace Characters {
		#define ZOMBIE_SIZE_X 30.0f
		#define ZOMBIE_SIZE_Y 60.0f
		#define ZOMBIE_HP 100.0f
		#define ZOMBIE_DAMAGE 50.0f
		#define ZOMBIE_SPEED 80.0f
		class Zombie : public Enemy
		{
		public:
			Zombie(Math::CoordF pos = Math::CoordF(0, 0), Player* p1 = nullptr, Player* p2 = nullptr);
			~Zombie();
			void attack();
			void update(float dt);
			void collide(Entity* ent, Math::CoordF intersection, float dt);
		};
	}
}

