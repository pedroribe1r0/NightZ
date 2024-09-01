#pragma once
#include "MovingEntity.h"
class EntitiesList;

namespace Entities {
	namespace Characters {
		#define JUMP -300.0f
		#define TIME_DMG_ANIMATION 0.8f
		#define DEATH_TIME 2.25f
		class Character : public MovingEntity
		{
		protected:
			float hp;
			float timeDamageAnimation;
			float deathTimeCounter;
			bool canJump;
			bool isAlive;
			bool takingDamage;
			bool isDying;
			/*To do*/
		public:
			Character(Math::CoordF pos = Math::CoordF(0, 0), Math::CoordF size = Math::CoordF(0, 0), ID id = ID::empty, float hp = 0);
			virtual ~Character();
			void takeDamage(float damage);
			void jump(float mult = 1);
			virtual void damage() = 0;
			virtual void update(float dt) = 0;
			virtual void collide(Entity* ent, Math::CoordF intersection, float dt) = 0;
			bool getCanJump() const;
			void setCanJump(bool cj);
			void execute(float dt);
			void moveOnCollision(Entity* ent, Math::CoordF intersection);
			bool getIsAlive() const;
			float getSpeedY() const;
			void setHp(float hp);
		};
	}
}

