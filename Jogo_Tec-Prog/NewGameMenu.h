#pragma once
#include "MainMenu.h"

namespace Menu {
	class NewGameMenu : public Menu {
	private:
		EntitiesList staticEntities;
		EntitiesList movingEntities;
		Managers::CollisionManager* pCollision;
		Managers::EventsManager* pEvent;
		GraphicalElements::Parallax::Background background;

	public:
		NewGameMenu();
		NewGameMenu(const ID id, std::string name, const unsigned int fontSize = 180);
		virtual ~NewGameMenu();
		virtual void createButtons();
		void createBackground();
		void execute(float dt);
		void render();
		void manageCollisions(float dt);
	};

}
