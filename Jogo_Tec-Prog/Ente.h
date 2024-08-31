#pragma once
#include "Animation.h"


enum ID {
	empty = 0,
	player,
	enemy,
	boss,
	obstacle,
	projectile,
	roundsingleplayer_id,
	timesingleplayer_id,
	roundmultiplayer_id,
	timemultiplayer_id,
	background,
	main_menu,
	newgame_menu,
	round_singleplayer_button,
	round_multiplayer_button,
	time_singleplayer_button,
	time_multiplayer_button,
	loadgame_button,
	leaderboards_menu,
	exit_button,
	pause_menu,
	resumegame_button,
	save_button,
	gameover_menu,
	levelcomplete_menu
};
namespace Entities {
	namespace Characters {
		class Player;
	}
}
class Ente
{
protected:
	ID id;
	static Managers::GraphicManager* pGraphic;
	sf::RectangleShape* body;
	static Entities::Characters::Player* pPlayer1;
	static Entities::Characters::Player* pPlayer2;
public:
	Ente(ID id = ID::empty);
	virtual ~Ente();
	void setID(ID id);
	ID getID() const;
	virtual void render() = 0;
	virtual void execute(float dt) = 0;
	static void setPlayers(Entities::Characters::Player* p1 = nullptr, Entities::Characters::Player* p2 = nullptr);
	static void setP1Null();
	static void setP2Null();
};

