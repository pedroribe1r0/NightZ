#pragma once
#include "Zombie.h"

class EntitiesList;
namespace Entities {
	class Projectile;
	namespace Characters {
		#define THROWER_SIZE_X 30.0f
		#define THROWER_SIZE_Y 85.0f
		#define THROWER_HP 90.0f
		#define THROWER_DAMAGE 5.0f
		#define THROWER_SPEED 50.0f
		#define THROWER_COOLDOWN 3.0f
		#define THROWER_ATTACK_TIME 3.0f
		class Thrower : public Enemy
		{
		private:
			Projectile* p;
			float cooldown;
			bool isAttacking;
			float attackTime;
		public:
			Thrower(Math::CoordF pos = Math::CoordF(0, 0), EntitiesList* list = nullptr);
			~Thrower();
			void attack();
			void update(float dt);
			void collide(Entity* ent, Math::CoordF intersection, float dt);
			void takeDistance(Player* p);
			void setTextures();
		};
	}
}

