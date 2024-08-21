#pragma once
#include "List.h"
#include "Player.h"
#include "Obstacle.h"

class EntitiesList
{
private:
	List<Entities::Entity> entitiesList;
public:
	EntitiesList();
	~EntitiesList();
	void execute(float dt);
	void update(float dt);
	void render();
	void setData(Entities::Entity* pEnt);
	void removeData(Entities::Entity* pEnt);
	int getSize() const;
	List<Entities::Entity>::iterator begin();
	List<Entities::Entity>::iterator end();
};

