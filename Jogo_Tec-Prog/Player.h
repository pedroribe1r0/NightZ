#pragma once
#include "Character.h"

namespace Observers {
	class PlayerObserver;
}

namespace Entities {
	class Projectile;
	namespace Characters {
		#define PLAYER_SIZE_X 32.0f
		#define PLAYER_SIZE_Y 88.0f
		#define PLAYER_SPEED 150.0f
		#define PARALIZE_TIME 0.5f
		#define PLAYER_HP 100.0f
		#define N_BULLETS 5
		#define SHOOT_COOLDOWN 0.63f
		class Player : public Character
		{
		private:
			Player* otherPlayer;
			Observers::PlayerObserver* pObserver;
			const bool isPlayer1;
			int points;
			float paralizeTimer;
			float shootCooldown;
			bool isShooting;
			bool canShoot;
			bool isRunning;
			float slow;
			std::vector<Projectile*> bulletVector;
		public:
			Player(Math::CoordF pos = Math::CoordF(0, 0), bool isPlayer1 = true, EntitiesList* list = nullptr, Player* other = nullptr);
			~Player();
			void update(float dt);
			void damage();
			void operator++();
			void collide(Entity* ent, Math::CoordF intersection, float dt);
			bool getIsPlayer1() const;
			void setIsParalized();
			void setTextures();
			void run();
			void stopRunning();
			void setOther(Player* p);
			void setSlow(bool s);
		};
	}
}


