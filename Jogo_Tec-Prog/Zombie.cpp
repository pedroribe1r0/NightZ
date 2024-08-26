#include "Zombie.h"

namespace Entities {
	namespace Characters {

		Zombie::Zombie(Math::CoordF pos, Player* p1, Player* p2) : Enemy(pos, Math::CoordF(ZOMBIE_SIZE_X, ZOMBIE_SIZE_Y), enemy, ZOMBIE_HP, p1, p2){
			meleeDamage = ZOMBIE_DAMAGE;
			if (body) {
				body->setFillColor(sf::Color::White);
			}
		}
		Zombie::~Zombie() {

		}
		void Zombie::attack() {

		}
		void Zombie::update(float dt) {
			stop();
			srand(time(NULL));
			if (rand() % 5 == 0) {
				jump();
			}
			
			if (pPlayer1 && pPlayer2) {
				if (fabs(position.x - pPlayer1->getPosition().x) < fabs(position.x - pPlayer2->getPosition().x)) {
					chasePlayer(pPlayer1);
				}
				else {
					chasePlayer(pPlayer2);
				}
			}
			else if (pPlayer1) {
				chasePlayer(pPlayer1);
				
			}
			else if (pPlayer2) {
				chasePlayer(pPlayer2);
			}
			if (isMoving) {
				if (facingLeft)
					speed.x = -ZOMBIE_SPEED;
				else
					speed.x = ZOMBIE_SPEED;
			}
			else {
				speed.x = 0;
			}
		}
		void Zombie::collide(Entity* ent, Math::CoordF intersection, float dt) {
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
