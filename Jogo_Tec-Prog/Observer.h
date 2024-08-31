#pragma once
#include "CollisionManager.h"

namespace Managers {
	class InputManager;
}
namespace States {
	class StateMachine;
}
namespace Observers {
	class Observer {
	protected:
		Managers::InputManager* pInput;
		bool isActive;
		bool isMoreActive;
		States::StateMachine* pMachine;
	public:
		Observer();
		virtual ~Observer();

		virtual void notifyKeyPressed(sf::Keyboard::Key key) = 0;
		virtual void notifyKeyReleased(sf::Keyboard::Key key) = 0;
		void setIsActive(bool iA);
		bool getIsActive();
		void setIsMoreActive(bool isMA);
		bool getIsMoreActive();
	};
}

