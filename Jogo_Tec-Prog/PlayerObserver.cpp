#include "PlayerObserver.h"
#include "PauseMenu.h"

namespace Observers {
	PlayerObserver::PlayerObserver(Entities::Characters::Player* pPlayer) : Observer(), pPlayer(pPlayer) {
		isActive = true;
		if (pPlayer) {
			if (pPlayer->getIsPlayer1()) {
				jump = sf::Keyboard::W;
				right = sf::Keyboard::D;
				left = sf::Keyboard::A;
				attack = sf::Keyboard::F;
				run = sf::Keyboard::LShift;
			}
			else {
				jump = sf::Keyboard::I;
				right = sf::Keyboard::L;
				left = sf::Keyboard::J;
				attack = sf::Keyboard::U;
				run = sf::Keyboard::H;
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
		if (key == right) {
			if (pPlayer->getCanMove()) {
				pPlayer->move(false);
			}
		}
		if (key == left) {
			if (pPlayer->getCanMove()) {
				pPlayer->move(true);
			}
		}
		if (key == attack) {
			pPlayer->damage();
		}
		if (key == run) {
			pPlayer->run();
		}
		if (key == sf::Keyboard::Key::Escape && pMachine->getCurrentState()->getID() != pause_menu) {
			Menu::PauseMenu* p = new Menu::PauseMenu();
		}
		
	}
	void PlayerObserver::notifyKeyReleased(sf::Keyboard::Key key) {
		if (key == right && !sf::Keyboard::isKeyPressed(left)) {
			if (pPlayer->getCanMove()) {
				pPlayer->stop();
			}
		}
		if (key == left && !sf::Keyboard::isKeyPressed(right)) {
			if (pPlayer->getCanMove()) {
				pPlayer->stop();
			}
		}
		if (key == run) {
			pPlayer->stopRunning();
		}
	}
	void PlayerObserver::setPlayer(Entities::Characters::Player* pPlayer) {
		if (pPlayer)
			this->pPlayer = pPlayer;
	}
}
