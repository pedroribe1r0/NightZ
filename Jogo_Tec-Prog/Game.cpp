#include "Game.h"

Game::Game() {
	Entities::Characters::Player* p1 = new Entities::Characters::Player(Math::CoordF(200,200), true, &movingEntities);
	//Entities::Characters::Player* p2 = new Entities::Characters::Player(Math::CoordF(550, 200), false);
	Entities::Characters::Zombie* z1 = new Entities::Characters::Zombie(Math::CoordF(650, 200), p1);
	movingEntities.setData(p1);
	//movingEntities.setData(p2);
	movingEntities.setData(z1);
	Entities::Obstacles::Obstacle* floor = new Entities::Obstacles::Obstacle(Math::CoordF(600, 720), Math::CoordF(1200, 10), false, 0);
	Entities::Obstacles::Obstacle* wall1 = new Entities::Obstacles::Obstacle(Math::CoordF(0, 720/2), Math::CoordF(10, 720), false, 0);
	Entities::Obstacles::Obstacle* wall2 = new Entities::Obstacles::Obstacle(Math::CoordF(1200, 720 / 2), Math::CoordF(10, 720), false, 0);
	staticEntities.setData(floor);
	staticEntities.setData(wall1);
	staticEntities.setData(wall2);
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
		pColision->collide(pGraphic->getDeltaTime());
		pEvent->pollEvents();
		movingEntities.execute(pGraphic->getDeltaTime());
		staticEntities.execute(pGraphic->getDeltaTime());
		movingEntities.render();
		staticEntities.render();
		pGraphic->display();
	}
}
