#include "Obstacle.h"

namespace Entities {
	namespace Obstacles {
		Obstacle::Obstacle(Math::CoordF pos, Math::CoordF size, bool dangerous, int damadge, const char* textPath) : Entity(pos, size, ID::obstacle), dangerous(dangerous), damage(damage){
			//body = new sf::Sprite();
			//body->setPosition(sf::Vector2f(pos.x, pos.y));
			if (body) {
				if (textPath) {
					body->setTexture(pGraphic->loadTexture(textPath));
				}
			}
		}
		Obstacle::~Obstacle() {

		}
		void Obstacle::update(float dt){}
		void Obstacle::execute(float dt){}
		void Obstacle::render() {
			pGraphic->render(body);
		}
		void Obstacle::collide(Entity* ent, Math::CoordF intersection, float dt){}
	}
}
