#include "Observer.h"
#include "InputManager.h"

namespace Observers {
	Observer::Observer(){
		pInput = Managers::InputManager::getInstance();

		pInput->addObserver(this);
		isActive = true;
	}

	Observer::~Observer() {
	}
	void Observer::setIsActive(bool iA) {
		isActive = iA;
	}
	bool Observer::getIsActive() {
		return isActive;
	}
}
