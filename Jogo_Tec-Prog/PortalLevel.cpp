#include "PortalLevel.h"

namespace States {
	namespace Levels {
		PortalLevel::PortalLevel() {
			Entities::Characters::Player* p1 = new Entities::Characters::Player(Math::CoordF(200, 600), true, movingEntities);
			Entities::Obstacles::Simple* floor = new Entities::Obstacles::Simple(Math::CoordF(960, 1030), Math::CoordF(7120, 10));
			staticEntities->setData(floor);
			//Entities::Obstacles::Obstacle* obs2 = new Entities::Obstacles::Obstacle(Math::CoordF(640, 360), Math::CoordF(100, 720), false, 0);
			movingEntities->setData(p1);
			//staticEntities->setData(obs2);
			//run();
		}
		PortalLevel::~PortalLevel() {

		}

		void PortalLevel::render() {
			movingEntities->render();
			staticEntities->render();
		}
		void PortalLevel::execute(float dt) {
			movingEntities->execute(dt);
			staticEntities->execute(dt);
		}
		void PortalLevel::run() {
			while (pGraphic->isWindowOpen()) {
				pGraphic->clear();
				pGraphic->updateDeltaTime();
				pColision->collide(pGraphic->getDeltaTime());
				pEvent->pollEvents();
				execute(pGraphic->getDeltaTime());
				render();
				pGraphic->display();
			}
		}
	}
}
