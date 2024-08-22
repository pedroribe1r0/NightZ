#pragma once
#include "Character.h"

namespace Observers {
	class PlayerObserver;
}

namespace Entities {
	//class MachineGun;
	namespace Characters {
		#define PLAYER_SIZE_X 30.0f
		#define PLAYER_SIZE_Y 60.0f
		#define PLAYER_SPEED 200.0f
		#define PLAYER_1_TEXTURE "luffy.png"
		#define PLAYER_2_TEXTURE "zoro.png"
		#define PLAYER_HP 100
		class Player : public Character
		{
		private:
			Observers::PlayerObserver* pObserver;
			const bool isPlayer1;
			int points;
			//MachineGun* gun;
		public:
			Player(Math::CoordF pos = Math::CoordF(0, 0), bool isPlayer1 = true);
			~Player();
			void update(float dt);
			void attack();
			void operator++();
			void collide(Entity* ent, Math::CoordF intersection, float dt);
			bool getIsPlayer1() const;
		};
	}
}


