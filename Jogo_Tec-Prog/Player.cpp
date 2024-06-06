#include "Player.h"

namespace Entities {
	namespace Characters {
		Player::Player(Math::CoordF pos, std::string text, bool isPlayer1) : 
		Entity(pos, Math::CoordF(PLAYER_SIZE_X, PLAYER_SIZE_Y), text ,player), 
		isPlayer1(isPlayer1)
		{
			speed.x = PLAYER_SPEED_X;
			speed.y = PLAYER_SPEED_Y;
		}
		Player::~Player() {}
		void Player::render() {
			pGraphic->render(textPath, position, size);
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
			
		}
	}
}