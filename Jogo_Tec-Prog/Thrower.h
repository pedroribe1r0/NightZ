#pragma once
#include "Zombie.h"

class EntitiesList;
namespace Entities {
	class Projectile;
	namespace Characters {
		#define THROWER_SIZE_X 30.0f
		#define THROWER_SIZE_Y 60.0f
		#define THROWER_HP 80.0f
		#define THROWER_DAMAGE 5.0f
		#define THROWER_SPEED 80.0f
		#define THROWER_COOLDOWN 2.0f
		class Thrower : public Enemy
		{
		private:
			Projectile* p;
			float cooldown;
		public:
			Thrower(Math::CoordF pos = Math::CoordF(0, 0), EntitiesList* list = nullptr);
			~Thrower();
			void attack();
			void update(float dt);
			void collide(Entity* ent, Math::CoordF intersection, float dt);
			void resetCooldown();
			void takeDistance(Player* p);
		};
	}
}

