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
	round_singleplayer_button, // vai para o seletor de fase
	round_multiplayer_button, // vai para o seletor de fase
	time_singleplayer_button, 
	time_multiplayer_button,
	level_menu, // menu seletor de fase
	loadgame_button,
	leaderboards_menu,
	exit_button,
	pause_menu,
	resumegame_button
	
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

