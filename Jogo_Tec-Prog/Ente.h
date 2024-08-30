#pragma once
#include "Animation.h"


enum ID {
	empty = 0,
	player,
	enemy,
	boss,
	obstacle,
	projectile,
	level1,
	level2,
	background
	//to do
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
	virtual void execute(float dt) = 0;
};

