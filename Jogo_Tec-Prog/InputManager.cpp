#include "InputManager.h"

namespace Managers{
	InputManager* InputManager::pInput = nullptr;

	InputManager* InputManager::getInstance() {
		if (!pInput)
			pInput = new InputManager();
		return pInput;
	}

	InputManager::InputManager() : observers(){

	}

	InputManager::~InputManager() {
		observers.clear();
	}

	void InputManager::handleKeyPressed(sf::Keyboard::Key key) {
		std::list<Observers::Observer*>::iterator it = observers.begin();
		while (it != observers.end()) {
			if ((*it)->getCanPress()) {
				if ((*it)->getIsActive()) {
					(*it)->notifyKeyPressed(key);
					++it;  // Incrementa o iterador
				}
				else {
					it = observers.erase(it);  // Apaga e recebe o próximo elemento
				}
			}
			else {
				(*it)->setCanPress(true);
				++it;  // Incrementa o iterador
			}
		}
	}
	void InputManager::handleKeyReleased(sf::Keyboard::Key key) {
		std::list<Observers::Observer*>::iterator it = observers.begin();
		while (it != observers.end()) {
			if ((*it)->getCanPress()) {
				if ((*it)->getIsActive()) {
					(*it)->notifyKeyReleased(key);
					++it;  // Incrementa o iterador
				}
				else {
					it = observers.erase(it);  // Apaga e recebe o próximo elemento
				}
			}
			else {
				(*it)->setCanPress(true);
				++it;  // Incrementa o iterador
			}
		}
	}
	void InputManager::addObserver(Observers::Observer* obs) {
		if (obs) {
			observers.push_back(obs);
			return;
		}
		std::cout << "Error! obs is nullptr" << endl;
	}
	void InputManager::removeObserver(Observers::Observer* obs) {
		if (obs) {
			observers.remove(obs);
			return;
		}
		std::cout << "Error! obs is nullptr" << endl;
	}
}
