#pragma once
#include "Obstacle.h"

namespace Entities {
	namespace Obstacles {
		class Simple : public Obstacle
		{
		public:
			Simple(Math::CoordF pos = Math::CoordF(0, 0), Math::CoordF size = Math::CoordF(0, 0), const char* textPath = nullptr, Math::CoordF scale = Math::CoordF(0, 0));
			~Simple();
			void update(float dt);
			void execute(float dt);
			void block(Characters::Player* ent, float dt);
			void setTextures();
			string save();
		};
	}
}

