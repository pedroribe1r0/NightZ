#include "Bonfire.h"

namespace Entities {
	namespace Obstacles {
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
			if (pPlayer1) {
				
				if (fabs(pPlayer1->getPosition().x - position.x) < 150 && fabs(pPlayer1->getPosition().x - position.x) > 50 && fabs(pPlayer1->getPosition().y - position.y) < 150) {
					isHealing1 = true;
				}
				else
					isHealing1 = false;
			}

			if (pPlayer2) {
				if (fabs(pPlayer2->getPosition().x - position.x) < 150 && fabs(pPlayer2->getPosition().x - position.x) > 50 && fabs(pPlayer2->getPosition().y - position.y) < 200) {
					isHealing2 = true;
				}
				else
					isHealing2 = false;
			}
		}
		void Bonfire::execute(float dt) {
			position.y += GRAVIDADE * dt;
			update(dt);
			if (pPlayer1) {
				if (isHealing1) {
					if (pPlayer1->getHp() < 100) {
						pPlayer1->heal(healRatio * dt);
					}
				}
				else
					pPlayer1->stopHeal();
			}
			if (pPlayer2) {
				if (isHealing2) {
					if (pPlayer2->getHp() < 100) {
						pPlayer2->heal(healRatio * dt);
					}
				}

				else
					pPlayer2->stopHeal();
			}
			sprite->update(GraphicalElements::Animation_ID::idle, true, position, dt);
		}
		void Bonfire::block(Characters::Player* ent, float dt) {
			if (ent->getIsPlayer1())
				isHealing1 = false;
			else
				isHealing2 = false;
		}
	}
}
