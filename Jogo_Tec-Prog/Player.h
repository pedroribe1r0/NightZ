#pragma once
#include "Character.h"

namespace Entities {
	namespace Characters {
		#define PLAYER_SIZE_X 200.0f
		#define PLAYER_SIZE_Y 150.0f
		#define PLAYER_SPEED_X 100.0f
		#define PLAYER_SPEED_Y 100.0f
		#define PLAYER_1_TEXTURE "luffy.png"
		#define PLAYER_2_TEXTURE "zoro.png"
		#define PLAYER_HP 100
		#define PLAYER_STAMINA 20
		class Player : public Character
		{
		private:
			const bool isPlayer1;
			int points;
		public:
			Player(Math::CoordF pos = Math::CoordF(0, 0), bool isPlayer1 = true);
			~Player();
			void update(float dt);
			void render();
			void attack();
			void operator++();
		};
	}
}


