#include "MenuState.h"

namespace States {

	Managers::StateManager* MenuState::pStateM = Managers::StateManager::getInstance();

	MenuState::MenuState(const States::stateID id) :
		State(id), menu(nullptr)
	{
		createMenu();
	}

	MenuState::~MenuState() {
		if (menu) {
			delete(menu);
			menu = nullptr;
		}
	}

	void MenuState::changeObserverState() {
		menu->changeObserverState();
	}

	Levels::Level* MenuState::getLevel() {
		if (
			id == States::stateID::gameover_menu_state ||
			id == States::stateID::pause_menu_state ||
			id == States::stateID::saveprogress_menu_state
			)
		{
			Menu::PauseMenu* levelMenu = dynamic_cast<Menu::PauseMenu*>(menu);
			return levelMenu->getLevel();
		}
		return nullptr;
	}

	Menu::Menu* MenuState::getMenu() {
		State* currentState = pStateM->getCurrentState();
		Levels::Level* level = nullptr;
		if (currentState != nullptr) {
			if (currentState->getID() == States::stateID::coinflip_state || currentState->getID() == States::stateID::coinflip_state) {
				PlayState* playState = static_cast<PlayState*>(currentState);
				level = playState->getLevel();
			}
			else if (currentState->getID() == States::stateID::pause_menu_state) {
				MenuState* menuState = static_cast<MenuState*>(currentState);
			}
		}
		switch (id) {
			case(States::stateID::mainmenu_state):
			{
				Menu::MainMenu* mainMenu = new Menu::MainMenu();
				if (mainMenu == nullptr) {
					std::cout << "MenuState::not possible to create main menu" << std::endl;
					exit(1);
				}
				mainMenu->createButtons();
				menu = static_cast<Menu::Menu*>(mainMenu);
			}
				break;
			case (States::stateID::pause_menu_state):
			{
				if (level == nullptr) {
					std::cout << "MenuState::not possible to point to level" << std::endl;
					exit(1);
				}
				Menu::PauseMenu* pauseMenu = new Menu::PauseMenu(level);
				if (pauseMenu == nullptr) {
					std::cout << "MenuState::not possible to create pause menu" << std::endl;
					exit(1);
				}
				pauseMenu->createButtons();
				menu = static_cast<Menu::Menu*>(pauseMenu);
			}
			case (States::stateID::gameover_menu_state):
			{
				if (level == nullptr) {
					std::cout << "MenuState::not possible to point to level" << std::endl;
					exit(1);
				}
				Menu::GameOverMenu* gameOverMenu = new Menu::GameOverMenu(level);
				if (gameOverMenu == nullptr) {
					std::cout << "MenuState::not possible to create game over menu" << std::endl;
					exit(1);
				}
				gameOverMenu->createButtons();
				menu = static_cast<Menu::Menu*>(gameOverMenu);
			}
			break;
		}
	}

	void MenuState::run() {
		menu->run();
	}

}