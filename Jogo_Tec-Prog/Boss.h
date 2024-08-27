#pragma once
#include "Projectile.h"
namespace Entities {
	namespace Characters {
		#define BOSS_SIZE_X 80.0f
		#define BOSS_SIZE_Y 120.0f
		#define BOSS_HP 400.0f
		#define BOSS_DAMAGE 50.0f
		#define BOSS_ATTACK_DAMAGE 90.0f
		#define BOSS_SPEED 25.0f
		#define BOSS_ATTACK_RANGE 100.0f
		#define BOSS_COOLDOWN 4.0f
		#define ATTACK_TIME 3.3f
		#define HIT_TIME 1.35f
		class Boss : public Enemy
		{
		private:
			float attackRange;
			float attackDamage;
			float cooldownTimer;
			float attackTime;
			bool canAttack;
			bool isAttacking;
		public:
			Boss(Math::CoordF pos = Math::CoordF(0, 0));
			~Boss();
			void collide(Entity* ent, Math::CoordF intersection, float dt);
			void update(float dt);
			void attack();
			void paralizePlayer(Player* p);
			void setTextures();
		};
	}
}

