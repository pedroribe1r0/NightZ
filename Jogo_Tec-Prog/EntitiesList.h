#pragma once
#include "List.h"
#include "Projectile.h"
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
	void notifyPlayerDeath(bool isPlayer1);
	List<Entities::Entity>::iterator begin();
	List<Entities::Entity>::iterator end();
};

