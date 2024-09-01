#pragma once
#include "LevelCompleteMenu.h"
namespace Menu {
	class LeaderBoardsMenu : public Menu
	{
	private:
		GraphicalElements::Parallax::Background background;
		vector<Button::Text*> textVector;
	public:
		LeaderBoardsMenu();
		~LeaderBoardsMenu();
		void createButtons();
		void render();
		void execute(float dt);
		void loadLeaderBoards(string line);
		void createLeaderBoard();
	};
}

