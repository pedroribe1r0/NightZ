#include "Observer.h"
#include "InputManager.h"

namespace Observers {
	Observer::Observer(){
		pInput = Managers::InputManager::getInstance();

		pInput->addObserver(this);
	}

	Observer::~Observer() {}
}
