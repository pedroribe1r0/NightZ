#include "Enemy.h"
#include "Projectile.h"

namespace Entities {
	namespace Characters {
		Player* Enemy::getPlayer1() {
			return pPlayer1;
		}
		Player* Enemy::getPlayer2() {
			return pPlayer2;
		}
		Enemy::Enemy(Math::CoordF pos, Math::CoordF size , ID id, float hp) : Character(pos, size, id ,hp){
			meleeDamage = 0;
		}
		Enemy::~Enemy() {
		}
		void Enemy::chasePlayer(Player* p) {
			if (fabs(p->getPosition().x - position.x) < MAX_DISTANCE) {
				if (p->getPosition().x > position.x) {
					move(false);
				}
				else {
					move(true);
				}
			}
		}
		void Enemy::collide(Entity* ent, Math::CoordF intersection, float dt) {
			switch (ent->getID()) {
			case ID::obstacle:
				moveOnCollision(ent, intersection);
				break;
			case enemy:
				moveOnCollision(ent, intersection);
				break;
			case boss:
				moveOnCollision(ent, intersection);
				break;
			case thrower:
				moveOnCollision(ent, intersection);
				break;
			case player: {
				Player* p = dynamic_cast<Player*>(ent);
				if (p && !isDying) {
					p->takeDamage(meleeDamage * dt);
				}
				if(id != boss)
					moveOnCollision(ent, intersection);
				break;
			}
			case projectile: {
				if ((hp - PLAYER_PROJECTILE_DAMAGE) <= 0) {
					Projectile* p = dynamic_cast<Projectile*>(ent);
					if (p->getUser()->getID() == player) {
						Player* pl = dynamic_cast<Player*>(p->getUser());
						pl->operator++();
					}
				}
				break;
			}
			default:
				break;
			}
		}
	}
}
