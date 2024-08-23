#include "Enemy.h"

namespace Entities {
	namespace Characters {
		Enemy::Enemy(Math::CoordF pos, Math::CoordF size , ID id, int hp, Player* p1, Player* p2) : Character(pos, size, id ,hp){
			pPlayer1 = p1;
			pPlayer2 = p2;
			meleeDamage = 0;
		}
		Enemy::~Enemy() {
			pPlayer1 = nullptr;
			pPlayer2 = nullptr;
		}
		void Enemy::setPlayer1(Player* p1) {
			pPlayer1 = p1;
		}
		void Enemy::setPlayer2(Player* p2) {
			pPlayer2 = p2;
		}
		void Enemy::chasePlayer(Player* p) {
			if (p->getPosition().x > position.x) {
				move(false);
			}
			else {
				move(true);
			}
			
		}
	}
}
