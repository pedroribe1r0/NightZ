#include "Obstacle.h"

namespace Entities {
	namespace Obstacles {
		Obstacle::Obstacle(Math::CoordF pos, Math::CoordF size, bool dangerous, int damadge) : Entity(pos, size, ID::obstacle), dangerous(dangerous), damage(damage){
			//setar textura
			if (body)
				body->setTexture(pGraphic->loadTexture("grass.png"));
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
