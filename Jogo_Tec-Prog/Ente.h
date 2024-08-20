#pragma once
#include "GraphicManager.h"

enum ID {
	empty = 0,
	player,
	obstacle,
	projectile
};

class Ente
{
protected:
	ID id;
	sf::RectangleShape* body;
	
	static Managers::GraphicManager* pGraphic;
public:
	Ente(ID id = ID::empty);
	virtual ~Ente();
	void setID(ID id);
	ID getID() const;
	virtual void render() = 0;
	virtual void update(float dt) = 0;
};

