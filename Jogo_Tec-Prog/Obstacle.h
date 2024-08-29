#pragma once
#include "Player.h"

namespace Entities {
	namespace Obstacles {
		class Obstacle : public Entity
		{
		private:
			bool dangerous;
			float damage;
		public:
			Obstacle(Math::CoordF pos = Math::CoordF(0, 0), Math::CoordF size = Math::CoordF(0, 0), bool dangerous = false, float damage = 0, const char* textPath = nullptr);
			~Obstacle();
			void collide(Entity* ent, Math::CoordF intersection, float dt);
			virtual void update(float dt) = 0;
			virtual void execute(float dt) = 0;
			virtual void block(Characters::Player* ent, float dt) = 0;
		};
	}
}

