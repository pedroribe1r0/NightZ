#pragma once
#include "MovingEntity.h"
class EntitiesList;

namespace Entities {
	namespace Characters {
		#define JUMP -300.0
		class Character : public MovingEntity
		{
		protected:
			int hp;
			bool canJump;
			bool isAlive;
			/*To do*/
		public:
			Character(Math::CoordF pos = Math::CoordF(0, 0), Math::CoordF size = Math::CoordF(0, 0), ID id = ID::empty, int hp = 0);
			virtual ~Character();
			void takeDamage(int damage);
			void jump();
			virtual void attack() = 0;
			virtual void update(float dt) = 0;
			virtual void collide(Entity* ent, Math::CoordF intersection, float dt) = 0;
			bool getCanJump() const;
			void setCanJump(bool cj);
			void execute(float dt);
			void moveOnCollision(Entity* ent, Math::CoordF intersection);
		};
	}
}

