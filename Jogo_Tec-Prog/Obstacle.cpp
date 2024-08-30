#include "Obstacle.h"

namespace Entities {
	namespace Obstacles {
		Obstacle::Obstacle(Math::CoordF pos, Math::CoordF size, bool dangerous, float damage) : Entity(pos, size, ID::obstacle), dangerous(dangerous), damage(damage){
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
