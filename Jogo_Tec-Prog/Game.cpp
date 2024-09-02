#include "Game.h"

Game::Game() {
	pMachine = States::StateMachine::getInstance();
	
	pGraphic = Managers::GraphicManager::getInstance();
	pEvent = Managers::EventsManager::getInstance();
	new Menu::MainMenu();
	run();
}
Game::~Game() {
	delete pMachine;
	delete pEvent;
}
void Game::run() {
	while (pGraphic->isWindowOpen() && pMachine->getCurrentState()) {
		pGraphic->clear();
		pGraphic->updateDeltaTime();
		pMachine->manageCollision(pGraphic->getDeltaTime());
		pMachine->executeState(pGraphic->getDeltaTime());
		pEvent->pollEvents();
		pMachine->renderState();
		pGraphic->display();
	}
}
