#pragma once
#include "Animation.h"


enum ID {
	empty = 0,
	player,
	enemy,
	obstacle,
	projectile,
	level1,
	level2,
	background
};

class Ente
{
protected:
	ID id;
	static Managers::GraphicManager* pGraphic;
	sf::RectangleShape* body;

public:
	Ente(ID id = ID::empty);
	virtual ~Ente();
	void setID(ID id);
	ID getID() const;
	virtual void render() = 0;
	virtual void update(float dt) = 0;
};

