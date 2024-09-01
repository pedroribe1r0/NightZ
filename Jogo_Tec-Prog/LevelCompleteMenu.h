#pragma once
#include "GameOverMenu.h"

namespace Menu {
	class LevelCompleteMenu : public Menu {
	private:
		GraphicalElements::Parallax::Background background;
		Button::Text text;
	public:
		LevelCompleteMenu();
		~LevelCompleteMenu();
		void createButtons();
		void render();
		void execute(float dt);
		void setText(string s);
		string getText();
		void saveLeaderboards();
		void backspace();
	};
}

