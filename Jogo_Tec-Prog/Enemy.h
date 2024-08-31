#pragma once
#include "Player.h"
namespace Entities {
	namespace Characters {
		#define MAX_DISTANCE 900.0f
		class Enemy : public Character
		{
		protected:
			float meleeDamage;
		public:
			Enemy(Math::CoordF pos = Math::CoordF(0, 0), Math::CoordF size = Math::CoordF(0, 0), ID id = ID::empty, float hp = 0);
			virtual ~Enemy();
			static Player* getPlayer1();
			static Player* getPlayer2();
			void collide(Entity* ent, Math::CoordF intersection, float dt);
			virtual void update(float dt) = 0;
			virtual void damage() = 0;
			void chasePlayer(Player* p);
		};
	}
}


