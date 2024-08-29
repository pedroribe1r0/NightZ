#include "Simple.h"

namespace Entities {
	namespace Obstacles {
		Simple::Simple(Math::CoordF pos, Math::CoordF size, const char* textPath) : Obstacle(pos, size, false, 0, textPath){

		}
		Simple::~Simple() {

		}
		void Simple::update(float dt) {
		//body->move(sf::Vector2f(0, -GRAVIDADE * dt));
		}
		void Simple::execute(float dt) {
		//	body->move(sf::Vector2f(0, GRAVIDADE * dt));
			update(dt);
		}
		void Simple::block(Characters::Player* ent, float dt){}
	}
}
