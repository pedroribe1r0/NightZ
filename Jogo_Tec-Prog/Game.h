#pragma once
#include "LevelMenu.h"

class Game
{
private:
	Managers::EventsManager* pEvent;
	Managers::CollisionManager* pColision;
	Managers::GraphicManager* pGraphic;
	States::StateMachine* pMachine;
public:
	Game();
	~Game();
	void run();
};

