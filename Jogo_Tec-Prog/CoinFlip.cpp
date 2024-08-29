#include "CoinFlip.h"

namespace Levels {
	CoinFlip::CoinFlip() {
		createLevel();
		createPlayers(true);
		run();
	}
	CoinFlip::~CoinFlip() {

	}

	void CoinFlip::createLevel() {
		//-------------------------------------- Chao ------------------------------------//
		
		//------------------------------------ Arvores -----------------------------------//
	}

	void CoinFlip::render() {
		movingEntities->render();
		staticEntities->render();
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
			background.run();
			render();
			background.renderFloor();
			pGraphic->display();
		}
	}
}
