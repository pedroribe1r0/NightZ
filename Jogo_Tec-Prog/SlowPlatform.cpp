#include "SlowPlatform.h"

namespace Entities {
	namespace Obstacles {
		SlowPlatform::SlowPlatform(Math::CoordF pos, Math::CoordF size) : Obstacle(pos, size, false, 0){
			slow = 0.5;
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

		}
	}
}
