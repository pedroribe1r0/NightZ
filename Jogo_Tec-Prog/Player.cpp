#include "Player.h"

namespace Entities {
	namespace Characters {
		Player::Player(Math::CoordF pos, bool isPlayer1) : 
		Character(pos, Math::CoordF(PLAYER_SIZE_X, PLAYER_SIZE_Y), player, Math::CoordF(PLAYER_SPEED_X, PLAYER_SPEED_Y), PLAYER_HP, PLAYER_STAMINA), 
		isPlayer1(isPlayer1),
		points(0)
		{
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

		void Player::update(float dt) {
			if (isPlayer1) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					position.x -= speed.x * dt;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					position.x += speed.x * dt;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					position.y -= speed.y * dt;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					position.y += speed.y * dt;
				}
			}
			else {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
					position.x -= speed.x * dt;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
					position.x += speed.x * dt;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
					position.y -= speed.y * dt;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
					position.y += speed.y * dt;
				}
			}
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