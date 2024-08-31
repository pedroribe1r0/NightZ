#include "GameOverMenu.h"
#define BUTTON_SIZE_X 100
#define BUTTON_SIZE_Y 100

namespace Menu {

	GameOverMenu::GameOverMenu() :
		Menu(ID::gameover_menu, sf::Vector2f(BUTTON_SIZE_X, BUTTON_SIZE_Y), "Game Over", 100) 
	{
		background.addLayer("menubg.png", 0.0f, GraphicalElements::LID::empty);

		title.setPos(sf::Vector2f(windowSize.x / 2.0f - title.getSize().x / 2.0f, 220.0f));
		title.setTextColor(sf::Color{ 255, 255, 255 });
		title.setFontSize(90);
		title.setBorderSize(8);

		createButtons();
	}

	GameOverMenu::~GameOverMenu() {

	}

	void GameOverMenu::createButtons() {
		addButton("Save Progress", sf::Vector2f(1650, 800), ID::save_button, sf::Color{ 62, 127, 93 });
		addButton("Exit to Main Menu", sf::Vector2f(1650, 950), ID::exit_button, sf::Color{ 62, 127, 93 });
		initializeIterator();
	}

	void GameOverMenu::render() {
		background.render();
		std::list<Button::TextButton*>::iterator aux;
		for (aux = textButtonList.begin(); aux != textButtonList.end(); aux++) {
			Button::TextButton* button = *aux;
			button->render();
			button = nullptr;
		}
		pGraphic->render(title.getText());
	}

	void GameOverMenu::execute(float dt) {
		pGraphic->centerView(Math::CoordF(windowSize.x / 2.0f, windowSize.y / 2.0f));
	}
}
