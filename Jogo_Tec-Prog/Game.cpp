#include "Game.h"

Game::Game() {
	pMachine = States::StateMachine::getInstance();
	
	pGraphic = Managers::GraphicManager::getInstance();
	pEvent = Managers::EventsManager::getInstance();
	//adicionar o primeiro estado(main menu)
	pMachine->pushState(new States::Levels::PortalLevel());
	run();
}
Game::~Game() {
	delete pMachine;
	delete pColision;
	delete pEvent;
}
void Game::run() {
	while (pGraphic->isWindowOpen()) {
		pGraphic->clear();
		pGraphic->updateDeltaTime();
		pMachine->manageCollision(pGraphic->getDeltaTime());
		pMachine->executeState(pGraphic->getDeltaTime());
		pEvent->pollEvents();
		pMachine->renderState();
		pGraphic->display();
	}
}
