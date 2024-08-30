#pragma once
#include "StateManager.h"
#include "CoinFlip.h"
#include "PortalLevel.h"
#include "MainMenu.h"

namespace Managers {
	class StateManager;
}

namespace States {
	class MenuState : public State {
	private:
		Menu::Menu* menu;

		static Managers::StateManager* pStateM;
		void createMenu();
	public:
		MenuState(const States::stateID id);
		~MenuState();
		void changeObserverState();
		Levels::Level* getLevel();
		Menu::Menu* getMenu();
		void run();
	};


}
