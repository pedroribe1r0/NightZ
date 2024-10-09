#include "Player.h"
#include "PlayerObserver.h"
#include "Projectile.h"
#include "Level.h"

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
			isHealing(false),
			healingCounter(0),
			isTeleporting(false),
			teleportingCounter(0),
			teleportFaceLeft(false),
			slow(1)
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
				sprite->addNewAnimation(GraphicalElements::Animation_ID::teleport, "Char_off_hand_dash_left.png", 3);
			}
			else {
				sprite->addNewAnimation(GraphicalElements::Animation_ID::teleport, "p2_dash.png", 3);
				sprite->addNewAnimation(GraphicalElements::Animation_ID::idle, "p2_idle.png", 8);
				sprite->addNewAnimation(GraphicalElements::Animation_ID::walk, "p2_walk.png", 16);
				sprite->addNewAnimation(GraphicalElements::Animation_ID::shoot, "p2_shoot.png", 17);
				sprite->addNewAnimation(GraphicalElements::Animation_ID::dmg, "p2_takedamage.png", 8);
				sprite->addNewAnimation(GraphicalElements::Animation_ID::death, "p2_takedamage.png", 8);
				sprite->addNewAnimation(GraphicalElements::Animation_ID::run, "p2_run.png", 8);
				
			}
			body->setOrigin(size.x / 2 + 16, size.y / 2 - 5); //numeracao na base do chute, mas funciona
		}

		Player::~Player() {
			position = Math::CoordF(0, 0);
			if (isPlayer1)
				Ente::setP1(nullptr);
			else
				Ente::setP2(nullptr);

			if (isPlayer1)
				pPlayer1 = nullptr;
			else
				pPlayer2 = nullptr;
			
			if (pObserver)
				pObserver->setIsActive(false);
			if (level) {
				level->setPlayerPoints(points);
			}
		}

		bool Player::getIsPlayer1() const{
			return isPlayer1;
		}
		void Player::setPoints(int points) {
			this->points = points;
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
						speed.x = -PLAYER_SPEED * 1.5 * slow;
					else
						speed.x = PLAYER_SPEED * 1.5 * slow;
				}
				else {
					if (facingLeft)
						speed.x = -PLAYER_SPEED * slow;
					else
						speed.x = PLAYER_SPEED * slow;
				}
			}
			else {
				speed.x = 0;
			}
			position.x += speed.x * dt;
			position.y += speed.y * dt;

			if (slow < 1)
				slow = 1;
			
			if (isHealing) {
				healingCounter += dt;
				if (healingCounter >= EFFECT_TIME * 2) {
					healingCounter = 0;
				}
				else if (healingCounter >= EFFECT_TIME) {
					body->setFillColor(sf::Color::White);
				}
				else {
					body->setFillColor(sf::Color(119, 221, 119));
				}
			}
			else {
				body->setFillColor(sf::Color::White);
			}
			updateSprite(dt);
			centerCamera();
		}
		void Player::centerCamera() {
			if (isPlayer1) {
				pGraphic->centerView(Math::CoordF(position.x, pGraphic->getWindowSize().y / 2));
				if (pPlayer2) {
					if (fabs(pPlayer2->getPosition().x - position.x) > 960) {
						pPlayer2->setPosition(Math::CoordF((position.x + 50.0f), position.y));
					}
				}
			}
			else {
				if (pPlayer2) {
					if (!pPlayer2->getIsActive()) {
						pGraphic->centerView(Math::CoordF(position.x, pGraphic->getWindowSize().y / 2));
					}
				}
				else {
					pGraphic->centerView(Math::CoordF(position.x, pGraphic->getWindowSize().y / 2));
				}
			}
		}
		void Player::updateSprite(float dt) {
			if (isTeleporting) {
				teleportingCounter += dt;
				sprite->update(GraphicalElements::teleport, teleportFaceLeft, position, dt);
				if (teleportingCounter >= 0.45) {
					teleportingCounter = 0;
					isTeleporting = false;
				}
			}
			else if (isShooting) {
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
		}
		int Player::getPoints() const {
			return points;
		}
		void Player::setIsTeleporting(bool left) {
			isTeleporting = true;
			teleportFaceLeft = left;
		}
		void Player::setSlow(float slow) {
			this->slow = slow;
		}
		void Player::stopHeal() {
			isHealing = false;
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
			//cout << isPlayer1 << " " << points << endl;
		}

		void Player::setIsParalized() {
			canMove = false;
			paralizeTimer = 0;
		}
		void Player::heal(float heal) {
			hp += heal;
			isHealing = true;
		}
		float Player::getHp() const {
			return hp;
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
			case thrower:
				moveOnCollision(ent, intersection);
			default:
				break;
			}

		}
		string Player::save() {
			string line = "";
			line += to_string(static_cast<int>(id)) + ' ';
			line += to_string(position.x) + ' ';
			line += to_string(position.y) + ' ';
			line += to_string(hp) + ' ';
			line += to_string(points) + ' ';
			line += to_string(isPlayer1) + ' ';
			return line;
		}
	}
}