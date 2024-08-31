#include "MainMenu.h"
#define BUTTON_SIZE_X 100
#define BUTTON_SIZE_Y 100


namespace Menu {
	MainMenu::MainMenu() :
		Menu(ID::main_menu, sf::Vector2f(BUTTON_SIZE_X, BUTTON_SIZE_Y), "NightZ", 190)
	{

		Entities::Characters::Zombie* z1 = new Entities::Characters::Zombie(Math::CoordF(500, 1000));
		Entities::Characters::Thrower* t1 = new Entities::Characters::Thrower(Math::CoordF(600, 1000), &movingEntities);
		Entities::Characters::Boss* b1 = new Entities::Characters::Boss(Math::CoordF(400, 1000));
		movingEntities.setData(z1);
		movingEntities.setData(t1);
		movingEntities.setData(b1);
		Entities::Obstacles::Simple* floor = new Entities::Obstacles::Simple(Math::CoordF(900, 1030), Math::CoordF(1200, 20));
		staticEntities.setData(floor);
		pCollision = new Managers::CollisionManager(&movingEntities, &staticEntities);
		
		title.setPos(sf::Vector2f(windowSize.x / 2.0f - title.getSize().x / 2.0f, 220.0f));
		title.setTextColor(sf::Color{ 255, 255, 255 });
		title.setFontSize(170);
		title.setBorderSize(8);
		createBackground();
		
		createButtons();
		pEvent = Managers::EventsManager::getInstance();
	}

	MainMenu::MainMenu(const ID id, std::string name, const unsigned int fontSize) :
		Menu(id, sf::Vector2f(BUTTON_SIZE_X, BUTTON_SIZE_Y), name, fontSize)
	{
		title.setPos(sf::Vector2f(windowSize.x / 2.0f - title.getSize().x / 2.0f, 25.0f));
		title.setTextColor(sf::Color{ 0, 200, 0 });
	}

	MainMenu::~MainMenu() {}

	void MainMenu::createButtons() {
		const float buttonPosX = windowSize.x / 2.0f - buttonSize.x / 2.0f;
		addButton("New Game", sf::Vector2f(1650, 900), ID::newgame_menu, sf::Color{ 62, 127, 93 });
		addButton("Load Game", sf::Vector2f(1650, 1050), ID::loadgame_button, sf::Color{ 62, 127, 93 });
		addButton("Leaderboards", sf::Vector2f(1650, 1200), ID::leaderboards_menu, sf::Color{ 62, 127, 93 });
		addButton("Exit", sf::Vector2f(1650, 1350), ID::exit_button, sf::Color{ 62, 127, 93 });
		initializeIterator();
	}

	void MainMenu::createBackground() {
		background.addLayer("layer11.png", 0.0f, GraphicalElements::LID::empty);
		background.addLayer("layer10.png", 0.00000005f, GraphicalElements::LID::empty);
		background.addLayer("layer9.png", 0.0000001f, GraphicalElements::LID::empty);
		background.addLayer("layer8.png", 0.000003f, GraphicalElements::LID::empty);
		background.addLayer("layer7.png", 0.00006f, GraphicalElements::LID::empty);
		background.addLayer("layer6.png", 0.0007f, GraphicalElements::LID::empty);
		background.addLayer("layer5.png", 0.0008f, GraphicalElements::LID::empty);
		background.addLayer("layer4.png", 0.0009f, GraphicalElements::LID::empty);
		background.addLayer("layer3.png", 0.005f, GraphicalElements::LID::empty);
		background.addLayer("layer2.png", 0.06f, GraphicalElements::LID::empty);
		background.addLayer("layer1.png", 0.08f, GraphicalElements::LID::empty);
		background.addLayer("layer0.png", 0.1f, GraphicalElements::LID::floor);
	}

	void MainMenu::execute(float dt) {
		movingEntities.execute(pGraphic->getDeltaTime());
		staticEntities.execute(pGraphic->getDeltaTime());
	}
	void MainMenu::render() {
		background.render();
		pGraphic->render(title.getText());
		std::list<Button::TextButton*>::iterator aux;
		for (aux = textButtonList.begin(); aux != textButtonList.end(); aux++) {
			Button::TextButton* button = *aux;
			button->render();
			button = nullptr;
		}
		movingEntities.render();
		staticEntities.render();
		background.renderFloor();
	}
	void MainMenu::manageCollisions(float dt) {
		pCollision->collide(dt);
	}
}