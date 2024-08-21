#pragma once
#include "CollisionManager.h"

namespace Managers {
	class InputManager;
}

namespace Observers {
	class Observer {
	private:
		Managers::InputManager* pInput;
	public:
		Observer();
		virtual ~Observer();

		virtual void notifyKeyPressed(sf::Keyboard::Key key) = 0;
		virtual void notifyKeyReleased(sf::Keyboard::Key key) = 0;

	};
}

