#include "EventsManager.h"

namespace Managers {

	EventsManager* EventsManager::pEvent = nullptr;

	EventsManager::EventsManager() {
		pGraphic = Managers::GraphicManager::getInstance();

		pInput = Managers::InputManager::getInstance();
	}

	EventsManager::~EventsManager() {
		pGraphic = nullptr;
		pEvent = nullptr;
	}

	EventsManager* EventsManager::getInstance() {
		if (!pEvent)
			pEvent = new EventsManager();
		return pEvent;
	}

	void EventsManager::pollEvents() {
		sf::Event e;
		while (pGraphic->pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				pGraphic->closeWindow();
			if (e.type == sf::Event::KeyPressed)
				pInput->handleKeyPressed(e.key.code);
			if (e.type == sf::Event::KeyReleased)
				pInput->handleKeyReleased(e.key.code);
		}
	}
}
