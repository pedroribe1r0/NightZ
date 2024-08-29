#include "Obstacle.h"

namespace Entities {
	namespace Obstacles {
		Obstacle::Obstacle(Math::CoordF pos, Math::CoordF size, bool dangerous, float damage, const char* textPath) : Entity(pos, size, ID::obstacle), dangerous(dangerous), damage(damage){
			if (body) {
				if (textPath) {
					body->setTexture(pGraphic->loadTexture(textPath));
				}
			}
		}
		Obstacle::~Obstacle() {

		}
		void Obstacle::collide(Entity* ent, Math::CoordF intersection, float dt) {
			if (ent->getID() == player) {
				Entities::Characters::Player* p = dynamic_cast<Entities::Characters::Player*>(ent);
				if (dangerous) {
					p->takeDamage(damage * dt);
				}
				block(p, dt);
			}
		}
	}
}
