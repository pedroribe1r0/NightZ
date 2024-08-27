#include "Enemy.h"

namespace Entities {
	namespace Characters {
		Player* Enemy::pPlayer1 = nullptr;
		Player* Enemy::pPlayer2 = nullptr;
		void Enemy::setPlayer1(Player* p1) {
			if (p1) {
				pPlayer1 = p1;
			}
				
		}
		void Enemy::setPlayer2(Player* p2) {
			if (p2)
				pPlayer2 = p2;
		}
		Enemy::Enemy(Math::CoordF pos, Math::CoordF size , ID id, float hp) : Character(pos, size, id ,hp){
			meleeDamage = 0;
		}
		Enemy::~Enemy() {
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
