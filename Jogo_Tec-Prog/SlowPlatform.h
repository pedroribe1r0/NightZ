#pragma once
#include "Portal.h"
namespace Entities {
	namespace Obstacles {
		class SlowPlatform : public Obstacle
		{
		private:
			float slow;
		public:
			SlowPlatform(Math::CoordF pos = Math::CoordF(0, 0), Math::CoordF size = Math::CoordF(0, 0));
			~SlowPlatform();
			void update(float dt);
			void execute(float dt);
			void block(Characters::Player* ent, float dt);
			void setTextures();
		};
	}
}

