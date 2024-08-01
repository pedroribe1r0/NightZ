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
		pGraphic->clear();
		EL.update(0);
		EL.render();
		pGraphic->display();
	}
}
