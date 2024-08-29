#include "Jumper.h"

namespace Entities {
	namespace Obstacles {
		Jumper::Jumper(Math::CoordF pos, const char* textPath) : Obstacle(pos,Math::CoordF(JUMPER_SIZE_X, JUMPER_SIZE_Y), false, 0, textPath), elasticity(2.0) {

		}
		Jumper::~Jumper() {

		}
		void Jumper::update(float dt) {
			position.y -= GRAVIDADE * dt;
		}
		void Jumper::execute(float dt) {
			position.y += GRAVIDADE * dt;
			update(dt);
		}
		void Jumper::block(Characters::Player* ent, float dt) {
			if (fabs(position.y + size.y/2 - ent->getPosition().y) >= ent->getSize().y ) {
				ent->setCanJump(true);
				ent->jump(-ent->getSpeedY() / JUMP + 0.5);
			}
		}
	}
}
