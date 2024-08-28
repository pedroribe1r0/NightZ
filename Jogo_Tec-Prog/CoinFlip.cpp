#include "CoinFlip.h"

namespace Levels {
	CoinFlip::CoinFlip() {
		Entities::Characters::Player* p2 = new Entities::Characters::Player(Math::CoordF(600, 600), false, movingEntities);
		Entities::Characters::Player* p1 = new Entities::Characters::Player(Math::CoordF(640, 600), true, movingEntities, p2);
		Entities::Obstacles::Obstacle* obs1 = new Entities::Obstacles::Obstacle(Math::CoordF(640, 1020), Math::CoordF(5280, 10), false, 0);
		Entities::Obstacles::Obstacle* obs2 = new Entities::Obstacles::Obstacle(Math::CoordF(20, 560), Math::CoordF(400, 1100), false, 0, "tree2.png");
		Entities::Obstacles::Obstacle* obs3 = new Entities::Obstacles::Obstacle(Math::CoordF(1920, 560), Math::CoordF(400,1100), false, 0, "tree2.png");
		Entities::Obstacles::Obstacle* obs4 = new Entities::Obstacles::Obstacle(Math::CoordF(1000, 1000), Math::CoordF(400, 400), false, 0, "bush.png");
		movingEntities->setData(p1);
		movingEntities->setData(p2);
		staticEntities->setData(obs1);
		staticEntities->setData(obs2);
		staticEntities->setData(obs3);
		staticEntities->setData(obs4);
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
