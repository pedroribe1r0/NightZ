#include "Projectile.h"

namespace Entities {
	Projectile::Projectile(Characters::Character* user) : MovingEntity(Math::CoordF(0,0), Math::CoordF(PROJECTILE_SIZE_X, PROJECTILE_SIZE_Y), projectile), user(user), fireTimer(0){
		canShoot = true;
		damage = PROJECTILE_DAMAGE;
		range = 0;
		isActive = false;
		if (body) {
			body->setFillColor(sf::Color::Blue);
		}
	}
	Projectile::~Projectile() {

	}
	bool Projectile::shoot(bool left) {
		if (canShoot) {
			if (left) {
				position.x = user->getPosition().x -user->getSize().x / 2;
			}
			else
				position.x = user->getPosition().x +user->getSize().x / 2;
			position.y = user->getPosition().y - 20;
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
			speed.y += GRAVIDADE/10 * dt;
		}
		if (!canShoot) {
			fireTimer += dt;
			if (fireTimer >= TIME_MAX) {
				isActive = false;
				canShoot = true;
				fireTimer = 0;
			}
		}
		update(dt);
		position.x += speed.x * dt;
		position.y += speed.y * dt;
		body->setPosition(sf::Vector2f(position.x, position.y));
	}
	void Projectile::update(float dt) {
		if (isMoving) {
			if (facingLeft)
				speed.x = -PROJECTILE_SPEED;
			else
				speed.x = PROJECTILE_SPEED;
		}
		else {
			speed.x = 0;
		}
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
				pChar->takeDamage(PROJECTILE_DAMAGE);
				isActive = false;
				canShoot = true;
			}
			if (ent->getID() == obstacle) {
				isActive = false;
				canShoot = true;
			}
		}
		else if (user->getID() == player) {
			if (ent->getID() == enemy) {
				Entities::Characters::Character* pChar = dynamic_cast<Entities::Characters::Character*>(ent);
				pChar->takeDamage(PROJECTILE_DAMAGE);
				isActive = false;
				canShoot = true;
			}
			if (ent->getID() == obstacle) {
				isActive = false;
				canShoot = true;
			}
		}
		
	}
}
