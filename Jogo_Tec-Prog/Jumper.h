#pragma once
#include "Simple.h"
namespace Entities {
	namespace Obstacles {
		#define JUMPER_SIZE_X 50.0f
		#define JUMPER_SIZE_Y 50.0f
		#define COLLIDING_TIME 0.45f
		class Jumper : public Obstacle
		{
		private:
			const float elasticity;
			bool isColiding;
			float counterTime;
		public:
			Jumper(Math::CoordF pos = Math::CoordF(0, 0));
			~Jumper();
			void update(float dt);
			void execute(float dt);
			void block(Characters::Player* ent, float dt);
			void setTextures();
			string save();
		};
	}
}

