#include "Game.h"

Game::Game() : p1(Math::CoordF(0, 0), "luffy.png", true) {
	pGraphic = Managers::GraphicManager::getInstance();
	run();
}
Game::~Game() {

}
void Game::run() {
	while (pGraphic->isWindowOpen()) {
		pGraphic->clear();
		p1.update(0);
		p1.render();
		pGraphic->display();
	}
}
