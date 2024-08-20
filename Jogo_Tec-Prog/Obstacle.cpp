#include "Obstacle.h"

namespace Entities {
	namespace Obstacles {
		Obstacle::Obstacle(Math::CoordF pos, Math::CoordF size, bool dangerous, int damadge) : Entity(pos, size, ID::obstacle), dangerous(dangerous), damadge(damadge){
			//setar textura
			body->setFillColor(sf::Color::Red);
		}
		Obstacle::~Obstacle() {

		}
		void Obstacle::collide(Entities::Characters::Character* pCharacter) {
			pCharacter->takeDamadge(damadge);
			//to do
		}
		void Obstacle::update(float dt){}
		void Obstacle::render() {
			pGraphic->render(body);
		}
	}
}
