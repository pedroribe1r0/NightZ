#include "CoinFlip.h"

namespace States {
	namespace Levels {
		CoinFlip::CoinFlip() {
			createLevel();
			createPlayers(true);
		}
		CoinFlip::~CoinFlip() {

		}

		void CoinFlip::render() {
			background.run();
			movingEntities->render();
			staticEntities->render();
			background.renderFloor();
		}
		void CoinFlip::execute(float dt) {
			
			movingEntities->execute(dt);
			staticEntities->execute(dt);
			if (spawnTime >= SPAWN_TIME) {
				spawnEnemies();
				spawnTime = 0;
			}
			spawnTime += dt;
		}
		void CoinFlip::run() {
			while (pGraphic->isWindowOpen()) {
				pGraphic->clear();
				pGraphic->updateDeltaTime();
				manageCollisions(pGraphic->getDeltaTime());
				pEvent->pollEvents();
				execute(pGraphic->getDeltaTime());
				render();
				pGraphic->display();
			}
		}
	}
}
