#pragma once
#include "MovingEntity.h"

namespace Entities {
	namespace Characters {
		#define PLAYER_SIZE_X 200.0f
		#define PLAYER_SIZE_Y 150.0f
		#define PLAYER_SPEED_X 0.1f
		#define PLAYER_SPEED_Y 0.1f
		#define PLAYER_1_TEXTURE "luffy.png"
		#define PLAYER_2_TEXTURE "zoro.png"
		class Player : public MovingEntity
		{
		private:
			const bool isPlayer1;
		public:
			Player(Math::CoordF pos = Math::CoordF(0, 0), bool isPlayer1 = true);
			~Player();
			void update(float dt);
			void render();
		};
	}
}


