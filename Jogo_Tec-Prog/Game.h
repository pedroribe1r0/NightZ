#pragma once
#include "EntitiesList.h"
class Game
{
private:
	Managers::GraphicManager* pGraphic;
	EntitiesList EL;

public:
	Game();
	~Game();
	void run();
};

