#include "Bonfire.h"

namespace Entities {
	namespace Obstacles {
		Characters::Player* Bonfire::p1 = nullptr;
		Characters::Player* Bonfire::p2 = nullptr;
		Bonfire::Bonfire(Math::CoordF pos) : Obstacle(pos, Math::CoordF(BONFIRE_SIZE_X, BONFIRE_SIZE_Y), true, BONFIRE_DAMAGE), isHealing1(false), isHealing2(false), healRatio(5.0f){
			setTextures();
		}
		Bonfire::~Bonfire() {

		}
		void Bonfire::setTextures() {
			sprite = new GraphicalElements::Animation(body, Math::CoordF(0.15f, 0.15f));
			sprite->addNewAnimation(GraphicalElements::Animation_ID::idle, "bonfire.png", 12);
		}
		void Bonfire::update(float dt) {
			position.y -= GRAVIDADE * dt;
			if (p1) {
				
				if (fabs(p1->getPosition().x - position.x) < 150 && fabs(p1->getPosition().x - position.x) > 50 && fabs(p1->getPosition().y - position.y) < 150) {
					isHealing1 = true;
				}
				else
					isHealing1 = false;
			}

			if (p2) {
				if (fabs(p2->getPosition().x - position.x) < 150 && fabs(p2->getPosition().x - position.x) > 50 && fabs(p2->getPosition().y - position.y) < 200) {
					isHealing2 = true;
				}
				else
					isHealing2 = false;
			}
		}
		void Bonfire::execute(float dt) {
			position.y += GRAVIDADE * dt;
			update(dt);
			if (p1) {
				if (isHealing1) {
					if (p1->getHp() < 100) {
						p1->heal(healRatio * dt);
					}
				}
				else
					p1->stopHeal();
			}
			if (p2) {
				if (isHealing2) {
					if (p2->getHp() < 100) {
						p2->heal(healRatio * dt);
					}
				}

				else
					p2->stopHeal();
			}
			sprite->update(GraphicalElements::Animation_ID::idle, true, position, dt);
		}
		void Bonfire::block(Characters::Player* ent, float dt) {
			if (ent->getIsPlayer1())
				isHealing1 = false;
			else
				isHealing2 = false;
		}
		void Bonfire::setPlayers(Entities::Characters::Player* pP1, Entities::Characters::Player* pP2) {
			if (pP1) {
				p1 = pP1;
			}
			if (pP2) {
				p2 = pP2;
			}
		}
	}
}
