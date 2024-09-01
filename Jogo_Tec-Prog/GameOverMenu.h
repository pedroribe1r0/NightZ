#pragma once
#include "PauseMenu.h"

namespace Menu {
	class GameOverMenu : public Menu {
	private:
		GraphicalElements::Parallax::Background background;
		Button::Text text;
	public:
		GameOverMenu();
		~GameOverMenu();
		void createButtons();
		void render();
		void execute(float dt);
		void setText(string s);
		string getText();
		void saveLeaderboards();
		void backspace();
	};


}

