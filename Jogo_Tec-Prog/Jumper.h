#pragma once
#include "Simple.h"
namespace Entities {
	namespace Obstacles {
		class Jumper : public Obstacle
		{
		private:
			const float elasticity;
		public:
			Jumper(Math::CoordF pos = Math::CoordF(0, 0), Math::CoordF size = Math::CoordF(0, 0), const char* textPath = nullptr);
			~Jumper();
			void update(float dt);
			void execute(float dt);
			void block(Characters::Player* ent, float dt);
		};
	}
}

