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
	background,
	main_menu,
	newgame_menu, //no main menu, quando selecionado vai para o menu onde escolhe o número de players
	singleplayer_button, // vai para o seletor de fase
	multiplayer_button, // vai para o seletor de fase
	level_menu, // menu seletor de fase
	loadgame_menu,
	leaderboards_menu,
	exit_button,
	pause_menu,
	round_button,
	portal_button
	
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

