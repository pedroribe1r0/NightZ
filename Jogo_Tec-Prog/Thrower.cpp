#include "Thrower.h"
#include "Projectile.h"
#include "EntitiesList.h"

namespace Entities {
	namespace Characters {
		Thrower::Thrower(Math::CoordF pos,EntitiesList* list, Player* pPlayer1, Player* pPlayer2) : Enemy(pos,Math::CoordF(THROWER_SIZE_X, THROWER_SIZE_Y),enemy, THROWER_HP, pPlayer1, pPlayer2), list(list) {
			p = new Projectile(this);
			list->setData(p);
			meleeDamage = THROWER_DAMAGE;
			if (body) {
				body->setFillColor(sf::Color::Yellow);
			}
		}
		Thrower::~Thrower() {
			/*if (p) {
				list->removeData(p);
				delete p;
				p = nullptr; // Certifique-se de que `p` não será mais usado.
			}*/
		}
		void Thrower::attack() {
			
		}
		void Thrower::update(float dt) {
			stop();
			Player* near = nullptr;
			if (pPlayer1 && pPlayer2) {
				near = pPlayer2;
				if (fabs(position.x - pPlayer1->getPosition().x) < fabs(position.x - pPlayer2->getPosition().x)) {
					near = pPlayer1;
				}
				p->updateRange(near);
				
				if (fabs(position.x - near->getPosition().x) <= 200) {
					p->shoot(facingLeft);
				}
				else
					chasePlayer(near);
			}
			else if (pPlayer1) {
				p->updateRange(pPlayer1);
				facingLeft = false;
				if (position.x - pPlayer1->getPosition().x) {
					facingLeft = true;
				}
				if (fabs(position.x - pPlayer1->getPosition().x) <= 200) {
					p->shoot(facingLeft);
				}
				else
					chasePlayer(pPlayer1);
				
			}
			else if (pPlayer2) {
				p->updateRange(pPlayer2);
				facingLeft = false;
				if (position.x - pPlayer2->getPosition().x) {
					facingLeft = true;
				}
				if (fabs(position.x - pPlayer2->getPosition().x) <= 200) {
					p->shoot(facingLeft);
				}
				else
					chasePlayer(pPlayer2);
			}
			if (isMoving) {
				if (facingLeft)
					speed.x = -THROWER_SPEED;
				else
					speed.x = THROWER_SPEED;
			}
			else {
				speed.x = 0;
			}
			
		}
		void Thrower::collide(Entity* ent, Math::CoordF intersection, float dt) {
			switch (ent->getID()) {
			case ID::obstacle:
				moveOnCollision(ent, intersection);
				break;
			case enemy:
				moveOnCollision(ent, intersection);
				break;
			case player: {
				Player* p = dynamic_cast<Player*>(ent);
				if (p) {
					p->takeDamage(meleeDamage * dt);
				}
				moveOnCollision(ent, intersection);
				break;
			}
			default:
				break;
			}
		}
	}
}
