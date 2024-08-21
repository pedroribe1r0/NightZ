#include "Player.h"
#include "PlayerObserver.h"

namespace Entities {
	namespace Characters {
		Player::Player(Math::CoordF pos, bool isPlayer1) :
			Character(pos, Math::CoordF(PLAYER_SIZE_X, PLAYER_SIZE_Y), player, PLAYER_HP, PLAYER_STAMINA),
			isPlayer1(isPlayer1),
			points(0)
		{
			pObserver = new Observers::PlayerObserver(this);
			if (isPlayer1)
				//body->setTexture(pGraphic->loadTexture(PLAYER_1_TEXTURE));
				body->setFillColor(sf::Color::Magenta);
			else
				//body->setTexture(pGraphic->loadTexture(PLAYER_2_TEXTURE));
				body->setFillColor(sf::Color::Blue);
		}

		Player::~Player() {}

		void Player::render() {
			pGraphic->render(body);
		}

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
			position.x += speed.x * dt;
			position.y += speed.y * dt;
			body->setPosition(sf::Vector2f(position.x, position.y));
		}

		void Player::attack() {
			/*to do*/
		}

		void Player::operator++() {
			points++;
		}

		void Player::collide(Entity* ent, Math::CoordF intersection) {
			switch (ent->getID()) {
			case ID::obstacle:
				moveOnCollision(ent, intersection);
				break;
			case player:
				moveOnCollision(ent, intersection);
				break;
			default:
				break;
			}

		}
	}
}