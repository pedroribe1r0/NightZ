#pragma once
#include "Entity.h"

namespace Entities {
	namespace Characters {
		#define PLAYER_SIZE_X 200.0f
		#define PLAYER_SIZE_Y 150.0f
		#define PLAYER_SPEED_X 0.1f
		#define PLAYER_SPEED_Y 0.1f
		class Player : public Entity
		{
		private:
			const bool isPlayer1;
			Math::CoordF speed;
			
		public:
			Player(Math::CoordF pos = Math::CoordF(0, 0), std::string text = nullptr, bool isPlayer1 = true);
			~Player();
			void update(float dt);
			void render();
		};
	}
}


