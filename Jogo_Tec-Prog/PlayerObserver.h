#pragma once
#include "Observer.h"

namespace Observers {
	class PlayerObserver : public Observer
	{
	private:
		Entities::Characters::Player* pPlayer;
		sf::Keyboard::Key right;
		sf::Keyboard::Key left;
		sf::Keyboard::Key jump;
		sf::Keyboard::Key attack;
		sf::Keyboard::Key run;
	public:
		PlayerObserver(Entities::Characters::Player* pPlayer = nullptr);
		~PlayerObserver();
		void notifyKeyPressed(sf::Keyboard::Key key);
		void notifyKeyReleased(sf::Keyboard::Key key);
		void setPlayer(Entities::Characters::Player* pPlayer = nullptr);
		void createLevel();
	};
}

