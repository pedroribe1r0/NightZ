#include "Simple.h"

namespace Entities {
	namespace Obstacles {
		Simple::Simple(Math::CoordF pos, Math::CoordF size, const char* textPath, Math::CoordF scale) : Obstacle(pos, size, false, 0){
			if (body) {
				if(textPath)
					body->setTexture(pGraphic->loadTexture(textPath));
				body->setScale(sf::Vector2f(scale.x, scale.y));
			}
		}
		Simple::~Simple() {

		}
		void Simple::update(float dt) {
			position.y -= GRAVIDADE * dt;
		}
		void Simple::execute(float dt) {
			position.y += GRAVIDADE * dt;
			update(dt);
		}
		void Simple::block(Characters::Player* ent, float dt){}
		void Simple::setTextures() {
			
		}
		string Simple::save() {
			string line = "";
			line += to_string(static_cast<int>(id)) + ' ';
			line += to_string(position.x) + ' ';
			line += to_string(position.y) + ' ';
			return line;
		}
	}
}
