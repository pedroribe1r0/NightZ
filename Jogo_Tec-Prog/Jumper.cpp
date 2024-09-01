#include "Jumper.h"

namespace Entities {
	namespace Obstacles {
		Jumper::Jumper(Math::CoordF pos) : Obstacle(pos,Math::CoordF(JUMPER_SIZE_X, JUMPER_SIZE_Y), false, 0), elasticity(2.0),isColiding(false){
			body->setFillColor(sf::Color(130, 130, 130, 240));
			setTextures();
		}
		Jumper::~Jumper() {

		}
		void Jumper::update(float dt) {
			position.y -= GRAVIDADE * dt;
			if (isColiding) {
				counterTime += dt;
				if (counterTime >= COLLIDING_TIME) {
					counterTime = 0;
					isColiding = false;
				}
				sprite->update(GraphicalElements::jump, true, position, dt);
			}
		}
		void Jumper::execute(float dt) {
			position.y += GRAVIDADE * dt;
			update(dt);
		}
		void Jumper::block(Characters::Player* ent, float dt) {
			if (fabs(position.y + size.y/2 - ent->getPosition().y) >= ent->getSize().y ) {
				ent->setCanJump(true);
				if (fabs(ent->getSpeedY()) < 700)
					ent->jump(-ent->getSpeedY() / JUMP + 0.5f);
				else
					ent->jump(-ent->getSpeedY() / JUMP);
				isColiding = true;
			}
		}
		void Jumper::setTextures() {
			sprite = new GraphicalElements::Animation(body, Math::CoordF(0.1f, 0.075f));
			sprite->addNewAnimation(GraphicalElements::Animation_ID::jump, "tirestack.png", 3);
			sprite->update(GraphicalElements::jump, true, position, 0);
		}
		string Jumper::save() {
			string line = "";
			line += to_string(static_cast<int>(id)) + ' ';
			line += to_string(position.x) + ' ';
			line += to_string(position.y) + ' ';
			return line;
		}
	}
}
