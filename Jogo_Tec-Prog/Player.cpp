#include "Player.h"

namespace Entities {
	namespace Characters {
		Player::Player(Math::CoordF pos, bool isPlayer1) : 
		Character(pos, Math::CoordF(PLAYER_SIZE_X, PLAYER_SIZE_Y), player, Math::CoordF(PLAYER_SPEED_X, PLAYER_SPEED_Y), PLAYER_HP, PLAYER_STAMINA), 
		isPlayer1(isPlayer1)
		{
			if (isPlayer1)
				body->setTexture(pGraphic->loadTexture(PLAYER_1_TEXTURE));
			else
				body->setTexture(pGraphic->loadTexture(PLAYER_2_TEXTURE));
		}

		Player::~Player() {}

		void Player::render() {
			pGraphic->render(body);
		}

		void Player::update(float dt) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				position.x -= speed.x;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				position.x += speed.x;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				position.y -= speed.y;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				position.y += speed.y;
			}
			body->setPosition(sf::Vector2f(position.x, position.y));
		}

		void Player::attack() {
			/*to do*/
		}

		void Player::operator++() {
			points++;
		}
	}
}