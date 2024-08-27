#pragma once
#include "Player.h"
namespace Entities {
	namespace Characters {
		class Enemy : public Character
		{
		protected:
			static Player* pPlayer1;
			static Player* pPlayer2;
			float meleeDamage;
		public:
			Enemy(Math::CoordF pos = Math::CoordF(0, 0), Math::CoordF size = Math::CoordF(0, 0), ID id = ID::empty, float hp = 0, Player* p1 = nullptr, Player* p2 = nullptr);
			virtual ~Enemy();
			void setPlayer1(Player* p1);
			void setPlayer2(Player* p2);
			virtual void collide(Entity* ent, Math::CoordF intersection, float dt) = 0;
			virtual void update(float dt) = 0;
			virtual void attack() = 0;
			void chasePlayer(Player* p);
		};
	}
}


