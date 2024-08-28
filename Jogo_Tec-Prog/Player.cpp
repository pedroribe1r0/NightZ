#include "Player.h"
#include "PlayerObserver.h"
#include "Projectile.h"

namespace Entities {
	namespace Characters {
		Player::Player(Math::CoordF pos, bool isPlayer1, EntitiesList* list, Player* other) :
			Character(pos, Math::CoordF(PLAYER_SIZE_X, PLAYER_SIZE_Y), player, PLAYER_HP),
			isPlayer1(isPlayer1),
			points(0),
			paralizeTimer(0),
			bulletVector(N_BULLETS),
			shootCooldown(0.2),
			isShooting(false),
			canShoot(true),
			isRunning(false),
			otherPlayer(other)
		{
			for (int i = 0; i < N_BULLETS; i++) {
				Projectile* p = new Projectile(this);
				bulletVector[i] = p;
				list->setData(p);
			}
			pObserver = new Observers::PlayerObserver(this);
			setTextures();
		}

		void Player::setTextures() {
			sprite = new GraphicalElements::Animation(body, Math::CoordF(1.8, 1.8));
			if (isPlayer1) {
				sprite->addNewAnimation(GraphicalElements::Animation_ID::walk, "Char_knife_walk.png", 16);
				sprite->addNewAnimation(GraphicalElements::Animation_ID::idle, "Char_knife_idle.png", 8);
				sprite->addNewAnimation(GraphicalElements::Animation_ID::shoot, "Char_knife_shoot.png", 17);
				sprite->addNewAnimation(GraphicalElements::Animation_ID::dmg, "Char_knife_take_damage.png", 8);
				sprite->addNewAnimation(GraphicalElements::Animation_ID::death, "Char_knife_take_damage.png", 8);
				sprite->addNewAnimation(GraphicalElements::Animation_ID::run, "Char_knife_run.png", 8);
			}
			else {
				sprite->addNewAnimation(GraphicalElements::Animation_ID::idle, "p2_idle.png", 8);
				sprite->addNewAnimation(GraphicalElements::Animation_ID::walk, "p2_walk.png", 16);
				sprite->addNewAnimation(GraphicalElements::Animation_ID::shoot, "p2_shoot.png", 17);
				sprite->addNewAnimation(GraphicalElements::Animation_ID::dmg, "p2_takedamage.png", 8);
				sprite->addNewAnimation(GraphicalElements::Animation_ID::death, "p2_takedamage.png", 8);
				sprite->addNewAnimation(GraphicalElements::Animation_ID::run, "p2_run.png", 8);
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
			if (isMoving) {
				if (isRunning) {
					if (facingLeft)
						speed.x = -PLAYER_SPEED * 1.5;
					else
						speed.x = PLAYER_SPEED * 1.5;
				}
				else {
					if (facingLeft)
						speed.x = -PLAYER_SPEED;
					else
						speed.x = PLAYER_SPEED;
				}
			}
			else {
				speed.x = 0;
			}
			position.x += speed.x * dt;
			position.y += speed.y * dt;

			if (isShooting) {
				shootCooldown += dt;
				sprite->update(GraphicalElements::Animation_ID::shoot, facingLeft, position, dt);
				if (shootCooldown >= SHOOT_COOLDOWN && shootCooldown < SHOOT_COOLDOWN + 0.5f && canShoot) {
					for (int i = 0; i < N_BULLETS; i++) {
						if (bulletVector[i]->getCanShoot()) {
							bulletVector[i]->shoot(facingLeft);
							canShoot = false;
							break;
						}
					}
				}
				if (shootCooldown >= 1.19) {
					shootCooldown = 0;
					isShooting = false;
					canShoot = true;
				}
			}
			else if (takingDamage) {
				sprite->update(GraphicalElements::Animation_ID::dmg, facingLeft, position, dt);
				timeDamageAnimation += dt;
				if (timeDamageAnimation >= TIME_DMG_ANIMATION) {
					timeDamageAnimation = 0;
					takingDamage = false;
				}
			}
			else if (isRunning && isMoving) {
				sprite->update(GraphicalElements::Animation_ID::run, facingLeft, position, dt);
			}
			else if (isMoving) {
				sprite->update(GraphicalElements::Animation_ID::walk, facingLeft, position, dt);
			}
			else {
				sprite->update(GraphicalElements::Animation_ID::idle, facingLeft, position, dt);
			}

			if (isPlayer1) {
				pGraphic->centerView(Math::CoordF(position.x, pGraphic->getWindowSize().y / 2));
				if (otherPlayer) {
					if (fabs(otherPlayer->getPosition().x - position.x) > 960) {
						otherPlayer->setPosition(Math::CoordF((position.x + 50.0f), position.y));
					}
				}
			}
		}
		void Player::run() {
			isRunning = true;
		}
		void Player::stopRunning() {
			isRunning = false;
		}
		void Player::damage() {
			isShooting = true;
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
			case boss:
				moveOnCollision(ent, intersection);
			default:
				break;
			}

		}
	}
}