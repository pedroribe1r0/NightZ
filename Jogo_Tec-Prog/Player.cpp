#include "Player.h"
#include "PlayerObserver.h"
#include "Projectile.h"

namespace Entities {
	namespace Characters {
		Player::Player(Math::CoordF pos, bool isPlayer1, EntitiesList* list) :
			Character(pos, Math::CoordF(PLAYER_SIZE_X, PLAYER_SIZE_Y), player, PLAYER_HP),
			isPlayer1(isPlayer1),
			points(0),
			paralizeTimer(0),
			bulletVector(N_BULLETS),
			shootCooldown(0.2),
			isShooting(false)
		{
			for (int i = 0; i < N_BULLETS; i++) {
				Projectile* p = new Projectile(this);
				bulletVector[i] = p;
				list->setData(p);
			}
			pObserver = new Observers::PlayerObserver(this);
			if (body) {
				if (isPlayer1)
					//body->setTexture(pGraphic->loadTexture(PLAYER_1_TEXTURE));
					body->setFillColor(sf::Color::White);
				else
					//body->setTexture(pGraphic->loadTexture(PLAYER_2_TEXTURE));
					body->setFillColor(sf::Color::White);
			}
		}

		Player::~Player() {
			position = Math::CoordF(-10, 0);
			if (isPlayer1)
				Enemy::setPlayer1(nullptr);
			else
				Enemy::setPlayer2(nullptr);

			if (pObserver)
				delete pObserver;
		}

		bool Player::getIsPlayer1() const{
			return isPlayer1;
		}

		void Player::update(float dt) {
			if (!canMove) {
				paralizeTimer += dt;
				if (paralizeTimer >= PARALIZE_TIME) {
					canMove = true;
				}
			}
			shootCooldown += dt;
			if (isShooting) {
				if (shootCooldown >= SHOOT_COOLDOWN) {
					shootCooldown = 0;
					for (int i = 0; i < N_BULLETS; i++) {
						if (bulletVector[i]->getCanShoot()) {
							bulletVector[i]->shoot(facingLeft);
							break;
						}
					}
				}
			}
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
			isShooting = true;
		}

		void Player::stopAttacking() {
			isShooting = false;
		}

		void Player::operator++() {
			points++;
		}

		void Player::setIsParalized() {
			canMove = false;
			paralizeTimer = 0;
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