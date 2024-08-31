#include "LevelCompleteMenu.h"
#define BUTTON_SIZE_X 100
#define BUTTON_SIZE_Y 100

namespace Menu {

	LevelCompleteMenu::LevelCompleteMenu() :
		Menu(ID::levelcomplete_menu, sf::Vector2f(BUTTON_SIZE_X, BUTTON_SIZE_Y), "Level Complete", 100)
	{
		background.addLayer("menubg.png", 0.0f, GraphicalElements::LID::empty);

		title.setPos(sf::Vector2f(windowSize.x / 2.0f - title.getSize().x / 2.0f, 220.0f));
		title.setTextColor(sf::Color{ 255, 255, 255 });
		title.setFontSize(90);
		title.setBorderSize(8);

		cout << pMachine->getPreviousState()->getID() << endl;

		createButtons();
	}

	LevelCompleteMenu::~LevelCompleteMenu() {

	}

	void LevelCompleteMenu::createButtons() {
		if (pMachine->getPreviousState()->getID() == roundsingleplayer_id) {
			addButton("Play Again", sf::Vector2f(1650, 800), ID::round_singleplayer_button, sf::Color{ 62, 127, 93 });
			addButton("Play Time Level", sf::Vector2f(1650, 950), ID::time_singleplayer_button, sf::Color{ 62, 127, 93 });
		}

		else if (pMachine->getPreviousState()->getID() == timesingleplayer_id) {
			addButton("Play Again", sf::Vector2f(1650, 800), ID::time_singleplayer_button, sf::Color{ 62, 127, 93 });
			addButton("Play Round Level", sf::Vector2f(1650, 950), ID::round_singleplayer_button, sf::Color{ 62, 127, 93 });
		}

		else if (pMachine->getPreviousState()->getID() == roundmultiplayer_id) {
			addButton("Play Again", sf::Vector2f(1650, 800), ID::round_multiplayer_button, sf::Color{ 62, 127, 93 });
			addButton("Play Time Level", sf::Vector2f(1650, 950), ID::time_multiplayer_button, sf::Color{ 62, 127, 93 });
		}

		else if (pMachine->getPreviousState()->getID() == timemultiplayer_id) {
			addButton("Play Again", sf::Vector2f(1650, 800), ID::time_multiplayer_button, sf::Color{ 62, 127, 93 });
			addButton("Play Round Level", sf::Vector2f(1650, 950), ID::round_multiplayer_button, sf::Color{ 62, 127, 93 });
		}

		addButton("Save Progress", sf::Vector2f(1650, 1100), ID::save_button, sf::Color{ 62, 127, 93 });
		addButton("Exit to Main Menu", sf::Vector2f(1650, 1250), ID::exit_button, sf::Color{ 62, 127, 93 });
		initializeIterator();
	}

	void LevelCompleteMenu::render() {
		background.render();
		std::list<Button::TextButton*>::iterator aux;
		for (aux = textButtonList.begin(); aux != textButtonList.end(); aux++) {
			Button::TextButton* button = *aux;
			button->render();
			button = nullptr;
		}
		pGraphic->render(title.getText());
	}

	void LevelCompleteMenu::execute(float dt) {
		pGraphic->centerView(Math::CoordF(windowSize.x / 2.0f, windowSize.y / 2.0f));
	}
}
