#include "PlayerObserver.h"

namespace Observers {
	PlayerObserver::PlayerObserver(Entities::Characters::Player* pPlayer) : Observer(), pPlayer(pPlayer) {
		if (pPlayer) {
			if (pPlayer->getIsPlayer1()) {
				jump = sf::Keyboard::W;
				right = sf::Keyboard::D;
				left = sf::Keyboard::A;
				attack = sf::Keyboard::F;
			}
			else {
				jump = sf::Keyboard::I;
				right = sf::Keyboard::L;
				left = sf::Keyboard::J;
				attack = sf::Keyboard::H;
			}
		}
	}
	PlayerObserver::~PlayerObserver() {
		pPlayer = nullptr;
	}
	void PlayerObserver::notifyKeyPressed(sf::Keyboard::Key key) {
		if (key == jump) {
			if (pPlayer->getCanJump()) {
				pPlayer->jump();
			}
		}
		else if (key == right) {
			if (pPlayer->getCanMove()) {
				pPlayer->move(false);
			}
		}
		else if (key == left) {
			if (pPlayer->getCanMove()) {
				pPlayer->move(true);
			}
		}
		/*else if (key == attack) {
			pPlayer->attack();
		}*/
	}
	void PlayerObserver::notifyKeyReleased(sf::Keyboard::Key key) {
		if (key == right) {
			if (pPlayer->getCanMove()) {
				pPlayer->stop();
			}
		}
		else if (key == left) {
			if (pPlayer->getCanMove()) {
				pPlayer->stop();
			}
		}
	}
	void PlayerObserver::setPlayer(Entities::Characters::Player* pPlayer) {
		if (pPlayer)
			this->pPlayer = pPlayer;
	}
}
