#pragma once
#include "EventsManager.h"
class Level : public Ente
{
private:
	Managers::EventsManager* pEvent;
	Managers::CollisionManager* pColision;
	EntitiesList* staticEntities;
	EntitiesList* movingEntities;
public:
	Level();
	~Level();
	virtual void execute(float dt) = 0;
	void manageCollisions();
	void createThrowers();
	void createThrowers();
};

