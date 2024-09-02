#include "GameOverMenu.h"
#define BUTTON_SIZE_X 100
#define BUTTON_SIZE_Y 100

namespace Menu {

	GameOverMenu::GameOverMenu() :
		Menu(ID::gameover_menu, sf::Vector2f(BUTTON_SIZE_X, BUTTON_SIZE_Y), "Game Over", 100), text(pGraphic->loadFont("yoster.ttf"), "", 40)
	{
		background.addLayer("menubg.png", 0.0f, GraphicalElements::LID::empty);

		title.setPos(sf::Vector2f(windowSize.x / 2.0f - title.getSize().x / 2.0f, 220.0f));
		title.setTextColor(sf::Color{ 255, 255, 255 });
		title.setFontSize(90);
		title.setBorderSize(8);
		text.setTextColor(sf::Color{ 255, 255, 255 });
		text.setFontSize(60);
		text.setBorderSize(8);
		text.setPos(sf::Vector2f((windowSize.x / 2.0f - text.getSize().x), windowSize.y/2));
		createButtons();
	}

	GameOverMenu::~GameOverMenu() {

	}

	void GameOverMenu::setText(string s) {
		string st = text.getString();
		st += s;
		text.setString(st);
	}

	void GameOverMenu::createButtons() {
		addButton("Save Progress", sf::Vector2f(1650, 1250), ID::save_button, sf::Color{ 62, 127, 93 });
		addButton("Exit to Main Menu", sf::Vector2f(1650, 1400), ID::exit_button, sf::Color{ 62, 127, 93 });
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
		text.setPos(sf::Vector2f((windowSize.x / 2.0f - text.getSize().x/2.0f), windowSize.y/2));
		pGraphic->render(title.getText());
		pGraphic->render(text.getText());
	}

	string GameOverMenu::getText() {
		return text.getString();
	}

	void GameOverMenu::backspace() {
		string st = text.getString();
		st.pop_back();
		text.setString(st);
	}

	void GameOverMenu::execute(float dt) {
		pGraphic->centerView(Math::CoordF(windowSize.x / 2.0f, windowSize.y / 2.0f));
	}
	void GameOverMenu::saveLeaderboards() {
		Managers::FileManager file;
		string s = "";
		if (pPlayer1 && pPlayer2) {
			level->setPlayerPoints(pPlayer1->getPoints() + pPlayer2->getPoints());
		}
		else if (pPlayer1) {
			level->setPlayerPoints(pPlayer1->getPoints());
		}
		else if (pPlayer2) {
			level->setPlayerPoints(pPlayer2->getPoints());
		}
		s += text.getString() + " " + to_string(level->getPlayerPoints());
		file.saveContent("./leaderboards.txt", s);
	}
}
