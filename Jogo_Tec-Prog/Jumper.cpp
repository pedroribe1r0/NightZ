#include "Jumper.h"

namespace Entities {
	namespace Obstacles {
		Jumper::Jumper(Math::CoordF pos, Math::CoordF size, const char* textPath) : Obstacle(pos,size, false, 0, textPath), elasticity(2.0){

		}
		Jumper::~Jumper() {

		}
		void Jumper::update(float dt) {
			//body->move(sf::Vector2f(0, -GRAVIDADE * dt));
		}
		void Jumper::execute(float dt) {
			//body->move(sf::Vector2f(0, -GRAVIDADE * dt));
			//update(dt);
		}
		void Jumper::block(Characters::Player* ent, float dt) {
			if (fabs(position.y + size.y/2 - ent->getPosition().y) >= ent->getSize().y ) {
				ent->setCanJump(true);
				ent->jump(-ent->getSpeedY() / JUMP + 0.5);
			}
		}
	}
}
