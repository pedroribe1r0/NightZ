#pragma once
#include "Bonfire.h"

namespace Entities {
	namespace Obstacles {
		#define PORTAL_SIZE_X 25.0f
		#define PORTAL_SIZE_Y 50.0f
		class Portal : public Obstacle
		{
		private:
			Portal* connected;
			bool facingRight;
		public:
			Portal(Math::CoordF pos = Math::CoordF(0, 0), bool right = false);
			~Portal();
			void update(float dt);
			void execute(float dt);
			void block(Characters::Player* ent, float dt);
			void connectPortal(Portal* p);
			void setTextures();
			bool isFacingRight() const;
			string save();
		};
	}
}

