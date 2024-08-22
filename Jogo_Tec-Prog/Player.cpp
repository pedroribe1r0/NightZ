#include "Player.h"
#include "PlayerObserver.h"
#include "MachineGun.h"

namespace Entities {
	namespace Characters {
		Player::Player(Math::CoordF pos, bool isPlayer1, EntitiesList* list) :
			Character(pos, Math::CoordF(PLAYER_SIZE_X, PLAYER_SIZE_Y), player, PLAYER_HP),
			isPlayer1(isPlayer1),
			points(0)
		{
			pObserver = new Observers::PlayerObserver(this);
			gun = new MachineGun(list, this);
			if (isPlayer1)
				//body->setTexture(pGraphic->loadTexture(PLAYER_1_TEXTURE));
				body->setFillColor(sf::Color::Magenta);
			else
				//body->setTexture(pGraphic->loadTexture(PLAYER_2_TEXTURE));
				body->setFillColor(sf::Color::Blue);
		}

		Player::~Player() {}

		bool Player::getIsPlayer1() const{
			return isPlayer1;
		}

		void Player::update(float dt) {
			if (isMoving) {
				if (facingLeft)
					speed.x = -PLAYER_SPEED;
				else
					speed.x = PLAYER_SPEED;
			}
			else {
				speed.x = 0;
			}
		}

		void Player::attack() {
			gun->shoot();
		}

		void Player::stopAttacking() {
			gun->stopShoot();
		}

		void Player::operator++() {
			points++;
		}

		void Player::collide(Entity* ent, Math::CoordF intersection, float dt) {
			switch (ent->getID()) {
			case ID::obstacle:
				moveOnCollision(ent, intersection);
				break;
			case player:
				moveOnCollision(ent, intersection);
				break;
			case enemy:
				moveOnCollision(ent, intersection);
				break;
			default:
				break;
			}

		}
	}
}