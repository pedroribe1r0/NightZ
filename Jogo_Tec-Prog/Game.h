#pragma once
#include "LeaderBoardsMenu.h"

class Game
{
private:
	Managers::EventsManager* pEvent;
	Managers::GraphicManager* pGraphic;
	States::StateMachine* pMachine;
public:
	Game();
	~Game();
	void run();
};

