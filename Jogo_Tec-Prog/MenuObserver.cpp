#include "MenuObserver.h"
#include "LeaderBoardsMenu.h"

namespace Observers {
		MenuObserver::MenuObserver(Menu::Menu* menu) :
			Observer(), menu(menu) 
		{
			select = sf::Keyboard::Enter;
			up = sf::Keyboard::Up;
			down = sf::Keyboard::Down;
			right = sf::Keyboard::Right;
			left = sf::Keyboard::Left;
			esc = sf::Keyboard::Escape;
		};

		MenuObserver::~MenuObserver() {
			
		}

		void MenuObserver::notifyKeyPressed(const sf::Keyboard::Key key) {
			if (pMachine->getCurrentState()) {
				if (pMachine->getCurrentState()->getID() == menu->getID()) {
					if (key == select) {
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
						else if (pMachine->getCurrentState()->getID() == pause_menu) {
							switch (menu->getSelectedButtonID()) {
							case ID::save_button: {
								Menu::PauseMenu* p = dynamic_cast<Menu::PauseMenu*>(menu);
								p->saveLevel();
								break;
							}
							case ID::exit_button: {
								pMachine->popState(3);
								break;
							}
							case ID::resumegame_button: {
								pMachine->popState();
								break;
							}
							}
						}
						else if (pMachine->getCurrentState()->getID() == main_menu) {
							switch (menu->getSelectedButtonID()) {
							case ID::newgame_menu: {
								Menu::NewGameMenu* n = new Menu::NewGameMenu();
								break;
							}
							case ID::loadgame_button: {
								Managers::FileManager file;
								vector<string> lines = file.lerArquivo("levelSave.txt");
								stringstream ss(lines[0]);
								int id;
								ss >> id;
								Menu::NewGameMenu* n = new Menu::NewGameMenu();
								if (id == static_cast<int>(roundmultiplayer_id)) {
									States::Levels::RoundLevel* r = new States::Levels::RoundLevel(true, true);
								}
								else if (id == static_cast<int>(roundsingleplayer_id)) {
									States::Levels::RoundLevel* r = new States::Levels::RoundLevel(false, true);
								}
								else if (id == static_cast<int>(timemultiplayer_id)) {
									States::Levels::TimeLevel* r = new States::Levels::TimeLevel(true, true);
								}
								else if (id == static_cast<int>(timesingleplayer_id)) {
									States::Levels::TimeLevel* r = new States::Levels::TimeLevel(false, true);
								}
								break;
							}
							case ID::leaderboards_menu: {
								Menu::LeaderBoardsMenu* m = new Menu::LeaderBoardsMenu();
								break;
							}
							case ID::exit_button: {
								pMachine->popState();
								break;
							}
							}
						}

						else if (pMachine->getCurrentState()->getID() == gameover_menu) {
							switch (menu->getSelectedButtonID()) {
							case ID::save_button: {
								Managers::FileManager file;
								Menu::GameOverMenu* m = dynamic_cast<Menu::GameOverMenu*>(menu);
								m->saveLeaderboards();
								pMachine->popState(3);
								break;
							}
							case ID::exit_button: {
								pMachine->popState(3);
								break;
							}
							}
						}

						else if (pMachine->getCurrentState()->getID() == levelcomplete_menu) {
							//cout << menu->getSelectedButtonID() << endl;
							switch (menu->getSelectedButtonID()) {
							case ID::round_singleplayer_button: {
								pMachine->popState(2);
								States::Levels::RoundLevel* r = new States::Levels::RoundLevel(false);
								break;
							}
							case ID::round_multiplayer_button: {
								pMachine->popState(2);
								States::Levels::RoundLevel* r = new States::Levels::RoundLevel(true);
								break;
							}
							case ID::time_singleplayer_button: {
								pMachine->popState(2);
								States::Levels::TimeLevel* t = new States::Levels::TimeLevel(false);
								break;
							}
							case ID::time_multiplayer_button: {
								pMachine->popState(2);
								States::Levels::TimeLevel* t = new States::Levels::TimeLevel(true);
								break;
							}
							case ID::save_button: {
								Managers::FileManager file;
								Menu::LevelCompleteMenu* m = dynamic_cast<Menu::LevelCompleteMenu*>(menu);
								m->saveLeaderboards();
							}
							case ID::exit_button: {
								pMachine->popState(3);
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
					else if (key == esc) {
						if (pMachine->getCurrentState()) {
							if (pMachine->getCurrentState()->getID() == pause_menu ||
								pMachine->getCurrentState()->getID() == newgame_menu ||
								pMachine->getCurrentState()->getID() == leaderboards_menu) {
								pMachine->popState();
							}
						}
					}
					else if (menu->getID() == gameover_menu && key == sf::Keyboard::Key::BackSpace) {
						Menu::GameOverMenu* g = dynamic_cast<Menu::GameOverMenu*>(menu);
						g->backspace();
					}
					else if (menu->getID() == gameover_menu) {
						Menu::GameOverMenu* g = dynamic_cast<Menu::GameOverMenu*>(menu);
						g->setText(keyToString(key));
					}
					else if (menu->getID() == levelcomplete_menu && key == sf::Keyboard::Key::BackSpace) {
						Menu::LevelCompleteMenu* g = dynamic_cast<Menu::LevelCompleteMenu*>(menu);
						g->backspace();
					}
					else if (menu->getID() == levelcomplete_menu) {
						Menu::LevelCompleteMenu* g = dynamic_cast<Menu::LevelCompleteMenu*>(menu);
						g->setText(keyToString(key));
					}
				}
			}
		}
	
			

		void MenuObserver::notifyKeyReleased(const sf::Keyboard::Key key) {

		}

		std::string MenuObserver::keyToString(sf::Keyboard::Key key) {
			switch (key) {
			case sf::Keyboard::A: return "A";
			case sf::Keyboard::B: return "B";
			case sf::Keyboard::C: return "C";
			case sf::Keyboard::D: return "D";
			case sf::Keyboard::E: return "E";
			case sf::Keyboard::F: return "F";
			case sf::Keyboard::G: return "G";
			case sf::Keyboard::H: return "H";
			case sf::Keyboard::I: return "I";
			case sf::Keyboard::J: return "J";
			case sf::Keyboard::K: return "K";
			case sf::Keyboard::L: return "L";
			case sf::Keyboard::M: return "M";
			case sf::Keyboard::N: return "N";
			case sf::Keyboard::O: return "O";
			case sf::Keyboard::P: return "P";
			case sf::Keyboard::Q: return "Q";
			case sf::Keyboard::R: return "R";
			case sf::Keyboard::S: return "S";
			case sf::Keyboard::T: return "T";
			case sf::Keyboard::U: return "U";
			case sf::Keyboard::V: return "V";
			case sf::Keyboard::W: return "W";
			case sf::Keyboard::X: return "X";
			case sf::Keyboard::Y: return "Y";
			case sf::Keyboard::Z: return "Z";
			default: return "";
			}
		}
}