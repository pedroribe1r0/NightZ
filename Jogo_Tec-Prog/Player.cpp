#include "Player.h"

namespace Entities {
	namespace Characters {
		Player::Player(Math::CoordF pos, bool isPlayer1) : 
		MovingEntity(pos, Math::CoordF(PLAYER_SIZE_X, PLAYER_SIZE_Y), player, Math::CoordF(PLAYER_SPEED_X, PLAYER_SPEED_Y)), 
		isPlayer1(isPlayer1)
		{
			if (isPlayer1)
				body.setTexture(PLAYER_1_TEXTURE);
			else
				body.setTexture(PLAYER_2_TEXTURE);
		}

		Player::~Player() {}

		void Player::render() {
			body.render();
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
			body.update(position);
		}
	}
}