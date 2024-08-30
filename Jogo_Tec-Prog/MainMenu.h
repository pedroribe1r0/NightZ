#pragma once
#include "Menu.h"

namespace Menu {
	class MainMenu : public Menu
	{
	private:
		EntitiesList staticEntities;
		EntitiesList movingEntities;
		Managers::CollisionManager* pCollision;

	public:
		MainMenu();
		MainMenu(const ID id, std::string name, const unsigned int fontSize = 180);
		virtual ~MainMenu();
		virtual void createButtons();
		virtual void run();
		void execute(float dt);
	};
}
