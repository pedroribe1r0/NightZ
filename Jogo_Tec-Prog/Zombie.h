#pragma once
#include "Enemy.h"

namespace Entities {
	namespace Characters {
		#define ZOMBIE_SIZE_X 30.0
		#define ZOMBIE_SIZE_Y 60.0
		#define ZOMBIE_HP 100.0
		#define ZOMBIE_DAMAGE 5.0
		#define ZOMBIE_SPEED 150.0
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

