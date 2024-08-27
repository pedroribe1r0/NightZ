#pragma once
#include "SingleFrameAnimation.h"


enum ID {
	empty = 0,
	player,
	enemy,
	weapon,
	bullet,
	obstacle,
	projectile
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

