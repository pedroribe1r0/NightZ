#pragma once
#include "MovingEntity.h"
class EntitiesList;

namespace Entities {
	namespace Characters {
		#define JUMP -300.0f
		#define TIME_DMG_ANIMATION 0.2f
		class Character : public MovingEntity
		{
		protected:
			float hp;
			float timeDamageAnimation;
			bool canJump;
			bool isAlive;
			/*To do*/
		public:
			Character(Math::CoordF pos = Math::CoordF(0, 0), Math::CoordF size = Math::CoordF(0, 0), ID id = ID::empty, float hp = 0);
			virtual ~Character();
			void takeDamage(float damage);
			void jump();
			virtual void attack() = 0;
			virtual void update(float dt) = 0;
			virtual void collide(Entity* ent, Math::CoordF intersection, float dt) = 0;
			bool getCanJump() const;
			void setCanJump(bool cj);
			void execute(float dt);
			void moveOnCollision(Entity* ent, Math::CoordF intersection);
			bool getIsAlive() const;
		};
	}
}

