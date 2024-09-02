#pragma once
#include "Menu.h"

namespace Menu {
	class MainMenu : public Menu
	{

	public:
		MainMenu();
		MainMenu(const ID id, std::string name, const unsigned int fontSize = 180);
		virtual ~MainMenu();
		void createButtons();
		void createBackground();
		void execute(float dt);
		void render();
		void manageCollisions(float dt);
	};
}
