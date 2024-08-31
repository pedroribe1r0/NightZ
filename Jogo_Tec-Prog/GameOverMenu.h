#pragma once
#include "PauseMenu.h"

namespace Menu {
	class GameOverMenu : public Menu {
	private:
		GraphicalElements::Parallax::Background background;

	public:
		GameOverMenu();
		~GameOverMenu();
		void createButtons();
		void render();
		void execute(float dt);
	};


}

