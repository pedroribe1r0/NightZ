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
			list->deleteData(p);
		}
		void Thrower::attack() {
			
		}
		void Thrower::update(float dt) {
			stop();
			p->updateRange(pPlayer1);
			if (pPlayer1) {
				if (fabs(position.x - pPlayer1->getPosition().x) <= 200) {
					p->shoot(facingLeft);
					//corrigir o lado do tiro antes de sair do range
				}
				else
					chasePlayer(pPlayer1);
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
