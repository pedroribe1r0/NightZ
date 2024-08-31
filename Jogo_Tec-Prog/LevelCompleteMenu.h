#pragma once
#include "GameOverMenu.h"

namespace Menu {
	class LevelCompleteMenu : public Menu {
	private:
		GraphicalElements::Parallax::Background background;

	public:
		LevelCompleteMenu();
		~LevelCompleteMenu();
		void createButtons();
		void render();
		void execute(float dt);
	};
}

