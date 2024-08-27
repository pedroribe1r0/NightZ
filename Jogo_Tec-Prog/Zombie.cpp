#include "Zombie.h"

namespace Entities {
	namespace Characters {

		Zombie::Zombie(Math::CoordF pos) : Enemy(pos, Math::CoordF(ZOMBIE_SIZE_X, ZOMBIE_SIZE_Y), enemy, ZOMBIE_HP){
			meleeDamage = ZOMBIE_DAMAGE;
			setTextures();
		}
		Zombie::~Zombie() {

		}
		void Zombie::attack() {

		}
		void Zombie::setTextures() {
			sprite = new GraphicalElements::Animation(body, Math::CoordF(2.8, 2.8));
			sprite->addNewAnimation(GraphicalElements::Animation_ID::walk, "Zombie _Walk.png", 9);
			sprite->addNewAnimation(GraphicalElements::Animation_ID::dmg, "Zombie _Hit.png", 4);
			sprite->addNewAnimation(GraphicalElements::Animation_ID::death, "Zombie_Death.png", 15);
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
			position.x += speed.x * dt;
			position.y += speed.y * dt;
			if (takingDamage) {
				sprite->update(GraphicalElements::Animation_ID::dmg, facingLeft, position, dt);
				timeDamageAnimation += dt;
				if (timeDamageAnimation >= TIME_DMG_ANIMATION) {
					timeDamageAnimation = 0;
					takingDamage = false;
				}
			}
			else if (isMoving) {
				sprite->update(GraphicalElements::Animation_ID::walk, facingLeft, position, dt);
			}
			else
				sprite->update(GraphicalElements::Animation_ID::walk, facingLeft, position, dt);
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
