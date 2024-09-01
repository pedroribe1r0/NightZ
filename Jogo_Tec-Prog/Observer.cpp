#include "Observer.h"
#include "InputManager.h"
#include "StateMachine.h"

namespace Observers {
	Observer::Observer(){
		pInput = Managers::InputManager::getInstance();

		pInput->addObserver(this);
		isDeleting = true;
		isActive = false;
		pMachine = States::StateMachine::getInstance();
	}

	Observer::~Observer() {
	}
	void Observer::setIsActive(bool iA) {
		isDeleting = iA;
	}
	bool Observer::getIsActive() {
		return isDeleting;
	}
	void Observer::setIsMoreActive(bool isMA) {
		isActive = isMA;
	}
	bool Observer::getIsMoreActive() {
		return isActive;
	}
}
