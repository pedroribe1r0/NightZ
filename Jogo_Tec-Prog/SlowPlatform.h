#pragma once
#include "Portal.h"
namespace Entities {
	namespace Obstacles {
		#define MUD_SIZE_X 300.0f
		#define MUD_SIZE_Y 20.0f
		class SlowPlatform : public Obstacle
		{
		private:
			float slow;
		public:
			SlowPlatform(Math::CoordF pos = Math::CoordF(0, 0));
			~SlowPlatform();
			void update(float dt);
			void execute(float dt);
			void block(Characters::Player* ent, float dt);
			void setTextures();
		};
	}
}

