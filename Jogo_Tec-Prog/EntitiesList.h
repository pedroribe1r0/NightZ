#pragma once
#include "List.h"
#include "Player.h"

class EntitiesList : public List<Entities::Entity>
{
public:
	EntitiesList();
	~EntitiesList();
	void update(float dt);
	void render();
};

