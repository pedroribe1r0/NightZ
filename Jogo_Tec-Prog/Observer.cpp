#include "Observer.h"
#include "InputManager.h"
#include "StateMachine.h"

namespace Observers {
	Observer::Observer(){
		pInput = Managers::InputManager::getInstance();

		pInput->addObserver(this);
		isActive = true;
		isMoreActive = false;
		pMachine = States::StateMachine::getInstance();
	}

	Observer::~Observer() {
	}
	void Observer::setIsActive(bool iA) {
		isActive = iA;
	}
	bool Observer::getIsActive() {
		return isActive;
	}
	void Observer::setIsMoreActive(bool isMA) {
		isMoreActive = isMA;
	}
	bool Observer::getIsMoreActive() {
		return isMoreActive;
	}
}
