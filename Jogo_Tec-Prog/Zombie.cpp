#include "Zombie.h"

namespace Entities {
	namespace Characters {

		Zombie::Zombie(Math::CoordF pos, Player* p1, Player* p2) : Enemy(pos, Math::CoordF(ZOMBIE_SIZE_X, ZOMBIE_SIZE_Y), enemy, ZOMBIE_HP, p1, p2){
			meleeDamage = ZOMBIE_DAMAGE;
			body->setFillColor(sf::Color::White);
		}
		Zombie::~Zombie() {

		}
		void Zombie::attack() {

		}
		void Zombie::update(float dt) {
			srand(time(NULL));
			if (rand() % 5 == 0) {
				jump();
			}
			if (fabs(position.x - pPlayer1->getPosition().x) < fabs(position.x - pPlayer2->getPosition().x)) {
				chasePlayer(pPlayer1, ZOMBIE_SPEED);
			}
			else {
				chasePlayer(pPlayer2, ZOMBIE_SPEED);
			}
		}
		void Zombie::collide(Entity* ent, Math::CoordF intersection) {
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
					p->takeDamage(meleeDamage);
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
