#pragma once
#include "EventsManager.h"
class Game
{
private:
	Managers::EventsManager* pEvent;
	Managers::GraphicManager* pGraphic;
	Managers::CollisionManager* pColision;
	EntitiesList staticEntities;
	EntitiesList movingEntities;
public:
	Game();
	~Game();
	void run();
};

