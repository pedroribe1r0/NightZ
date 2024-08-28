#include "CoinFlip.h"

namespace Levels {
	CoinFlip::CoinFlip() : Level(){
		createBackground();
		Entities::Characters::Player* p1 = new Entities::Characters::Player(Math::CoordF(200, 600), true, movingEntities);
		movingEntities->setData(p1);
		Entities::Characters::Enemy::setPlayer1(p1);
		Entities::Obstacles::Obstacle* obs1 = new Entities::Obstacles::Obstacle(Math::CoordF(640, 690), Math::CoordF(5280, 10), false, 0);
		staticEntities->setData(obs1);
		execute();
	}
	CoinFlip::~CoinFlip() {

	}

	void CoinFlip::render() {
		movingEntities->render();
		staticEntities->render();
	}
	void CoinFlip::update(float dt) {
		movingEntities->execute(dt);
		staticEntities->execute(dt);
		if (spawnTime >= SPAWN_TIME) {
			spawnEnemies();
			spawnTime = 0;
		}
		spawnTime += dt;
	}
	void CoinFlip::execute() {
		while (pGraphic->isWindowOpen()) {
			pGraphic->clear();
			pGraphic->updateDeltaTime();
			manageCollisions(pGraphic->getDeltaTime());
			pEvent->pollEvents();
			update(pGraphic->getDeltaTime());
			background.run();
			render();
			background.renderFloor();
			pGraphic->display();
		}
	}
}
