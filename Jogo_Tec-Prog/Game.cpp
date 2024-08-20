#include "Game.h"

Game::Game() {
	Entities::Characters::Player* p1 = new Entities::Characters::Player(Math::CoordF(200,200), true);
	EL.setData(p1);

	pGraphic = Managers::GraphicManager::getInstance();
	run();
}
Game::~Game() {

}
void Game::run() {
	while (pGraphic->isWindowOpen()) {
		pGraphic->updateDeltaTime();
		pGraphic->clear();
		EL.update(pGraphic->getDeltaTime());
		EL.render();
		pGraphic->display();
	}
}
