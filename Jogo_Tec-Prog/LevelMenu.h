#pragma once
#include "NewGameMenu.h"

namespace Menu {
	class LevelMenu : public Menu {
	private:
		EntitiesList staticEntities;
		EntitiesList movingEntities;
		Managers::CollisionManager* pCollision;
		Managers::EventsManager* pEvent;
		GraphicalElements::Parallax::Background background;

	public:
		LevelMenu();
		LevelMenu(const ID id, std::string name, const unsigned int fontSize = 180);
		virtual ~LevelMenu();
		virtual void createButtons();
		void createBackground();
		virtual void run();
		void execute(float dt);
	};

}