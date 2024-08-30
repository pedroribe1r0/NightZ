#include "MainMenu.h"
#define TITLE_SIZE_X 100
#define TITLE_SIZE_Y 100


namespace Menu {
	MainMenu::MainMenu() :
		Menu(ID::main_menu, sf::Vector2f(TITLE_SIZE_X, TITLE_SIZE_Y), "XUPACU", 100)
	{
		title.setPos(sf::Vector2f(windowSize.x / 2.0f - title.getSize().x / 2.0f, 25.0f));
		title.setTextColor(sf::Color{0, 200, 0});
	}

	MainMenu::MainMenu(const ID id, std::string name, const unsigned int fontSize) :
		Menu(id, sf::Vector2f(TITLE_SIZE_X, TITLE_SIZE_Y), name, fontSize)
	{
		title.setPos(sf::Vector2f(windowSize.x / 2.0f - title.getSize().x / 2.0f, 25.0f));
		title.setTextColor(sf::Color{ 0, 200, 0 });
	}

	MainMenu::~MainMenu () {}

	void MainMenu::createButtons() {
		const float buttonPosX = windowSize.x / 2.0f - buttonSize.x / 2.0f;
		addButton("New Game", sf::Vector2f(buttonPosX, windowSize.y / 2.0f), Button::newgame_button, sf::Color{ 0, 255, 0 });
		addButton("New Game", sf::Vector2f(buttonPosX, windowSize.y / 2.0f), Button::newgame_button, sf::Color{ 0, 255, 0 });
		//addButton("Load Game", sf::Vector2f(buttonPosX, windowSize.y / 2.0f + buttonSize.y * 1.2f), loadgame_button, sf::Color{ 0, 255, 0 });
		//addButton("Leaderboards", sf::Vector2f(buttonPosX, windowSize.y / 2.0f + buttonSize.y * 2.4f), leaderboards_button, sf::Color{ 0, 255, 0 });
		//addButton("Exit", sf::Vector2f(buttonPosX, windowSize.y / 2.0f + buttonSize.y * 3.6f), exit_button, sf::Color{ 0, 255, 0 });
		initializeIterator();
	}

	void MainMenu::run() {
		//CRIAR FASE POSTIÇA
		Entities::Characters::Zombie* z1 = new Entities::Characters::Zombie(Math::CoordF(650, 200));
		Entities::Characters::Thrower* t1 = new Entities::Characters::Thrower(Math::CoordF(800, 200));
		Entities::Characters::Boss* b1 = new Entities::Characters::Boss(Math::CoordF(600, 200));
		movingEntities.setData(z1);
		movingEntities.setData(t1);
		movingEntities.setData(b1);
		
		Entities::Obstacles::Obstacle* floor = new Entities::Obstacles::Obstacle(Math::CoordF(900, 1080), Math::CoordF(1200, 10), false, 0);
		staticEntities.setData(floor);
		pCollision = new Managers::CollisionManager(&movingEntities, &staticEntities);

		render();
		pGraphic->render(title.getText());
	}

	void MainMenu::execute(float dt) {

	}
}