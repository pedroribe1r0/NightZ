#include "Projectile.h"

namespace Entities {
	Projectile::Projectile(Characters::Character* user) : MovingEntity(Math::CoordF(0,0), Math::CoordF(PROJECTILE_SIZE_X, PROJECTILE_SIZE_Y), projectile), user(user), fireTimer(0){
		canShoot = true;
		range = 0;
		isActive = false;
		setTextures();
	}
	Projectile::~Projectile() {

	}
	void Projectile::setTextures() {
		if (user->getID() == player) {
			sprite = new GraphicalElements::Animation(body, Math::CoordF(1.5, 1.5));
			sprite->addNewAnimation(GraphicalElements::Animation_ID::idle, "6_1.png", 6);
			body->setFillColor(sf::Color(197, 179, 88));
		}
		else {
			sprite = new GraphicalElements::Animation(body, Math::CoordF(2.5, 2.5));
			sprite->addNewAnimation(GraphicalElements::Animation_ID::idle, "SpittingZombie - Projectile.png", 6);
		}
	}
	bool Projectile::shoot(bool left) {
		if (canShoot) {
			if (left) {
				position.x = user->getPosition().x -user->getSize().x / 2 - 30;
			}
			else
				position.x = user->getPosition().x +user->getSize().x / 2 + 30;
			if (user->getID() == player) {
				position.y = user->getPosition().y - 5;
			}
			else {
				position.y = user->getPosition().y - 20;
			}
			isActive = true;
			canShoot = false;
			speed.y = 0;
			move(left);
			return true;
		}
		return false;
	}
	bool Projectile::getCanShoot() const {
		return canShoot;
	}
	void Projectile::setCanShoot(bool canShoot) {
		this->canShoot = canShoot;
	}
	float Projectile::getRange() const {
		return range;
	}
	void Projectile::execute(float dt) {
		if (speed.y <= 800.0) {
			speed.y += GRAVIDADE / 10 * dt;
		}
		update(dt);
	}
	void Projectile::update(float dt) {
		if (isActive) {
			fireTimer += dt;
			if (fireTimer >= TIME_MAX) {
				isActive = false;
				canShoot = true;
				fireTimer = 0;
			}
		}
		if (isMoving) {
			if (facingLeft)
				speed.x = -PROJECTILE_SPEED;
			else
				speed.x = PROJECTILE_SPEED;
		}
		else {
			speed.x = 0;
		}
		position.x += speed.x * dt;
		position.y += speed.y * dt;
		sprite->update(GraphicalElements::Animation_ID::idle, facingLeft, position, dt);
	}
	/*void Projectile::updateRange(Characters::Player* p) {
		float s = p->getPosition().y + p->getSize().x / 2;
		float s0 = user->getPosition().y;
		float maxPosY = s0 - ((THROW_SPEED * THROW_SPEED) / (2 * GRAVIDADE));
		if (s >= maxPosY) {
			range = (s0 + PROJECTILE_SPEED * ((-THROW_SPEED / (2 * GRAVIDADE)) + sqrt((s - maxPosY) * 2 / GRAVIDADE)));
		}
		else {
			range = 0;
		}
		
	}*/
	void Projectile::collide(Entity* ent, Math::CoordF intersection, float dt) {
		if (user->getID() == enemy) {
			if (ent->getID() == player) {
				Entities::Characters::Character* pChar = dynamic_cast<Entities::Characters::Character*>(ent);
				pChar->takeDamage(THROWER_PROJECTILE_DAMAGE);
				isActive = false;
				canShoot = true;
				fireTimer = 0;
			}
			if (ent->getID() == obstacle) {
				isActive = false;
				canShoot = true;
				fireTimer = 0;
			}
		}
		else if (user->getID() == player) {
			if (ent->getID() == enemy || ent->getID() == boss) {
				Entities::Characters::Character* pChar = dynamic_cast<Entities::Characters::Character*>(ent);
				pChar->takeDamage(PLAYER_PROJECTILE_DAMAGE);
				isActive = false;
				canShoot = true;
				fireTimer = 0;
			}
			if (ent->getID() == obstacle) {
				isActive = false;
				canShoot = true;
				fireTimer = 0;
			}
		}
		
	}
}
