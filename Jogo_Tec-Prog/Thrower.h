#pragma once
#include "Zombie.h"

class EntitiesList;
namespace Entities {
	class Projectile;
	namespace Characters {
		#define THROWER_SIZE_X 30.0
		#define THROWER_SIZE_Y 60.0
		#define THROWER_HP 80.0
		#define THROWER_DAMAGE 5.0
		#define THROWER_SPEED 80.0
		class Thrower : public Enemy
		{
		private:
			Projectile* p;
			EntitiesList* list;
		public:
			Thrower(Math::CoordF pos = Math::CoordF(0, 0), EntitiesList* list = nullptr, Player* pPlayer1 = nullptr, Player* pPlayer2 = nullptr);
			~Thrower();
			void attack();
			void update(float dt);
			void collide(Entity* ent, Math::CoordF intersection, float dt);
		};
	}
}

