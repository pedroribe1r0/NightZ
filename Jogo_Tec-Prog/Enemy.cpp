#include "Enemy.h"

namespace Entities {
	namespace Characters {
		Player* Enemy::pPlayer1 = nullptr;
		Player* Enemy::pPlayer2 = nullptr;
		Enemy::Enemy(Math::CoordF pos, Math::CoordF size , ID id, float hp, Player* p1, Player* p2) : Character(pos, size, id ,hp){
			if (!pPlayer1) {
				pPlayer1 = p1;
			}
			if (!pPlayer2) {
				pPlayer2 = p2;
			}
			meleeDamage = 0;
		}
		Enemy::~Enemy() {
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
