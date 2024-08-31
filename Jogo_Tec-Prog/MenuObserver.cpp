#include "MenuObserver.h"

namespace Observers {
		MenuObserver::MenuObserver(Menu::Menu* menu) :
			Observer(), menu(menu) 
		{
			select = sf::Keyboard::Enter;
			up = sf::Keyboard::Up;
			down = sf::Keyboard::Down;
			right = sf::Keyboard::Right;
			left = sf::Keyboard::Left;
			goBack = sf::Keyboard::Escape;
		};

		MenuObserver::~MenuObserver() {
			
		}

		void MenuObserver::notifyKeyPressed(const sf::Keyboard::Key key) {
			if (isMoreActive) {
				if (pMachine->getCurrentState()) {
					if (key == select) {
						if (pMachine->getCurrentState()->getID() == main_menu) {
							switch (menu->getSelectedButtonID()) {
							case ID::newgame_menu: {
								Menu::NewGameMenu* n = new Menu::NewGameMenu();
								break;
							}
							case ID::loadgame_button: {
								//criar loadgame_menu
								break;
							}
							case ID::leaderboards_menu: {
								//criar leaderboards
								break;
							}
							case ID::exit_button: {
								pMachine->popState();
							}
							}
						}
						if (pMachine->getCurrentState()->getID() == newgame_menu) {
							switch (menu->getSelectedButtonID()) {
							case ID::round_singleplayer_button: {
								States::Levels::RoundLevel* r = new States::Levels::RoundLevel(false);
								break;
							}
							case ID::round_multiplayer_button: {
								States::Levels::RoundLevel* r = new States::Levels::RoundLevel(true);
								break;
							}
							case ID::time_singleplayer_button: {
								States::Levels::TimeLevel* t = new States::Levels::TimeLevel(false);
								break;
							}
							case ID::time_multiplayer_button: {
								States::Levels::TimeLevel* t = new States::Levels::TimeLevel(true);
								break;
							}
							}
						}

					}
					else if (key == up) {
						menu->selectAbove();
					}
					else if (key == down) {
						menu->selectBelow();
					}
					else if (key == goBack) {
						pMachine->popState();
					}
				}
			}
			else
				isMoreActive = true;
			
		}

		void MenuObserver::notifyKeyReleased(const sf::Keyboard::Key key) {

		}
}