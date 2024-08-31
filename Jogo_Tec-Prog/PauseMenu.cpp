#include "PauseMenu.h"
#include "Level.h"

#define BUTTON_SIZE_X 100
#define BUTTON_SIZE_Y 100

namespace Menu {
	PauseMenu::PauseMenu(States::Levels::Level* level):
		Menu(ID::pause_menu, sf::Vector2f(BUTTON_SIZE_X, BUTTON_SIZE_Y), "Game Paused", 105),
		level(level), panelBackground(sf::Vector2f(windowSize.x / 2.0f, windowSize.y))
	{

		panelBackground.setFillColor(sf::Color{ 0, 0, 0, 100 });
		panelBackground.setPosition(windowSize.x - panelBackground.getSize().x / 2.0f, windowSize.y - panelBackground.getSize().y / 2.0f);

		title.setPos(sf::Vector2f(windowSize.x / 2.0f - title.getSize().x / 2.0f, 220.0f));
		title.setTextColor(sf::Color{ 255, 255, 255 });
		title.setFontSize(90);
		title.setBorderSize(8);

		createButtons();
	}

	/*PauseMenu::PauseMenu(const ID id, std::string name, States::Levels::Level* level = ) :
		Menu(id, sf::Vector2f(BUTTON_SIZE_X, BUTTON_SIZE_Y), name, 90), level(level)
	{
		title.setPos(sf::Vector2f(windowSize.x / 2.0f - title.getSize().x / 2.0f, 25.0f));
		title.setTextColor(sf::Color{ 0, 200, 0 });
	}*/

	PauseMenu::~PauseMenu() {

	}

	void PauseMenu::createButtons() {
		addButton("Resume Game", sf::Vector2f(1650, 800), ID::resumegame_button, sf::Color{ 62, 127, 93 });
		addButton("Save Progress", sf::Vector2f(1650, 950), ID::save_button, sf::Color{ 62, 127, 93 });
		addButton("Exit to Main Menu", sf::Vector2f(1650, 1100), ID::exit_button, sf::Color{ 62, 127, 93 });
		initializeIterator();
	}

	void PauseMenu::setLevel(States::Levels::Level* level) {
		this->level = level;
	}

	States::Levels::Level* PauseMenu::getLevel() {
		return level;
	}

	void PauseMenu::render() {
		if (level) {
			level->render();
		}
		pGraphic->render(&panelBackground);
		std::list<Button::TextButton*>::iterator aux;
		for (aux = textButtonList.begin(); aux != textButtonList.end(); aux++) {
			Button::TextButton* button = *aux;
			button->render();
			button = nullptr;
		}
		pGraphic->render(title.getText());
	}

	void PauseMenu::execute(float dt) {}
}
