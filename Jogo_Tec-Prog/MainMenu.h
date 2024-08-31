#pragma once
#include "Menu.h"

namespace Menu {
	class MainMenu : public Menu
	{
	private:
		EntitiesList staticEntities;
		EntitiesList movingEntities;
		Managers::CollisionManager* pCollision;
		Managers::EventsManager* pEvent;
		GraphicalElements::Parallax::Background background;

	public:
		MainMenu();
		MainMenu(const ID id, std::string name, const unsigned int fontSize = 180);
		virtual ~MainMenu();
		virtual void createButtons();
		void createBackground();
		void execute(float dt);
		void render();
		void manageCollisions(float dt);
	};
}
