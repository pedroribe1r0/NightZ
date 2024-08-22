#pragma once
#include "Player.h"

namespace Entities {
	namespace Obstacles {
		class Obstacle : public Entity
		{
		private:
			bool dangerous;
			int damadge;
		public:
			Obstacle(Math::CoordF pos = Math::CoordF(0, 0), Math::CoordF size = Math::CoordF(0, 0), bool dangerous = false, int damadge = 0);
			~Obstacle();
			void collide(Entity* ent, Math::CoordF intersection, float dt);
			void render();
			void update(float dt);
			void execute(float dt);
		};
	}
}

