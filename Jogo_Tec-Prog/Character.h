#pragma once
#include "MovingEntity.h"

namespace Entities {
	namespace Characters {
		#define JUMP -250.0
		class Character : public MovingEntity
		{
		protected:
			int hp;
			bool canJump;
			/*To do*/
		public:
			Character(Math::CoordF pos = Math::CoordF(0, 0), Math::CoordF size = Math::CoordF(0, 0), ID id = ID::empty, int hp = 0);
			virtual ~Character();
			void takeDamage(int damage);
			void jump();
			virtual void attack() = 0;
			virtual void update(float dt) = 0;
			virtual void collide(Entity* ent, Math::CoordF intersection) = 0;
			bool getCanJump() const;
			void setCanJump(bool cj);
			void execute(float dt);
			void moveOnCollision(Entity* ent, Math::CoordF intersection);
		};
	}
}

