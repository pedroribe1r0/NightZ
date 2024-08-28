#include "CoinFlip.h"

namespace Levels {
	CoinFlip::CoinFlip() {
		Entities::Characters::Player* p1 = new Entities::Characters::Player(Math::CoordF(200, 600), true, movingEntities);
		Entities::Obstacles::Obstacle* obs1 = new Entities::Obstacles::Obstacle(Math::CoordF(640, 700), Math::CoordF(1280, 10), false, 0);
		movingEntities->setData(p1);
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
	}
	void CoinFlip::execute() {
		while (pGraphic->isWindowOpen()) {
			pGraphic->clear();
			pGraphic->updateDeltaTime();
			pColision->collide(pGraphic->getDeltaTime());
			pEvent->pollEvents();
			update(pGraphic->getDeltaTime());
			render();
			pGraphic->display();
		}
	}
}
