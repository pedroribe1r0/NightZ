#include "Game.h"

Game::Game() {
	Entities::Characters::Player* p1 = new Entities::Characters::Player(Math::CoordF(200,200), true);
	Entities::Characters::Player* p2 = new Entities::Characters::Player(Math::CoordF(550, 200), false);
	movingEntities.setData(p1);
	movingEntities.setData(p2);
	Entities::Obstacles::Obstacle* floor = new Entities::Obstacles::Obstacle(Math::CoordF(200, 720), Math::CoordF(600, 10), false, 0);
	staticEntities.setData(floor);
	pGraphic = Managers::GraphicManager::getInstance();
	pColision = new Managers::CollisionManager(&movingEntities, &staticEntities);
	pEvent = Managers::EventsManager::getInstance();
	run();
}
Game::~Game() {

}
void Game::run() {
	while (pGraphic->isWindowOpen()) {
		pGraphic->clear();
		pGraphic->updateDeltaTime();
		pEvent->pollEvents();
		movingEntities.execute(pGraphic->getDeltaTime());
		staticEntities.execute(pGraphic->getDeltaTime());
		pColision->collide();
		movingEntities.render();
		staticEntities.render();
		pGraphic->display();
	}
}
