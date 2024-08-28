#include "CoinFlip.h"

namespace Levels {
	CoinFlip::CoinFlip() {
		Entities::Characters::Player* p1 = new Entities::Characters::Player(Math::CoordF(200, 600), true, movingEntities);
		Entities::Obstacles::Obstacle* obs1 = new Entities::Obstacles::Obstacle(Math::CoordF(640, 690), Math::CoordF(5280, 10), false, 0);
		//Entities::Obstacles::Obstacle* obs2 = new Entities::Obstacles::Obstacle(Math::CoordF(0, 460), Math::CoordF(400, 600), false, 0);
		movingEntities->setData(p1);
		staticEntities->setData(obs1);
		//staticEntities->setData(obs2);
		Entities::Characters::Enemy::setPlayer1(p1);
		run();
	}
	CoinFlip::~CoinFlip() {

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
