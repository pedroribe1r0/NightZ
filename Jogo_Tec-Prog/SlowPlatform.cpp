#include "SlowPlatform.h"

namespace Entities {
	namespace Obstacles {
		SlowPlatform::SlowPlatform(Math::CoordF pos) : Obstacle(pos, Math::CoordF(MUD_SIZE_X, MUD_SIZE_Y), false, 0) {
			slow = 0.5;
			setTextures();
		}
		SlowPlatform::~SlowPlatform() {

		}
		void SlowPlatform::update(float dt) {
			position.y -= GRAVIDADE * dt;
		}
		void SlowPlatform::execute(float dt) {
			position.y += GRAVIDADE * dt;
			update(dt);
		}
		void SlowPlatform::block(Characters::Player* ent, float dt) {
			ent->setSlow(slow);
		}
		void SlowPlatform::setTextures() {
			if (body) {
				body->setTexture(pGraphic->loadTexture("mud.png"));
			}
		}
		string SlowPlatform::save() {
			string line = "";
			line += to_string(static_cast<int>(id)) + ' ';
			line += to_string(position.x) + ' ';
			line += to_string(position.y) + ' ';
			return line;
		}
	}
}
