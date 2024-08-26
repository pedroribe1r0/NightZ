#include "MachineGun.h"

namespace Entities {
	MachineGun::Bullet::Bullet(Math::CoordF pos, MachineGun* gun): Entity(pos, Math::CoordF(BULLET_RANGE, 4.0), ID::bullet), gun(gun){
		damage = BULLET_DAMAGE;
		if (body) {
			body->setFillColor(sf::Color::Green);
			//texture
		}
		position.y = gun->getPosition().y;
		position.x = gun->getPosition().x + gun->getSize().x / 2 + size.x / 2;
		isActive = false;
	}
	MachineGun::Bullet::~Bullet() {
		gun = nullptr;
	}
	void MachineGun::Bullet::execute(float dt) {
		body->setPosition(position.x, position.y);
	}
	void MachineGun::Bullet::update(float dt) {}
	void MachineGun::Bullet::followPlayer(bool left) {
		if(left)
			position.x = gun->getPosition().x - (gun->getSize().x / 2 + size.x / 2);
		else
			position.x = gun->getPosition().x + gun->getSize().x / 2 + size.x / 2;
		position.y = gun->getPosition().y;
	}
	void MachineGun::Bullet::collide(Entity* ent, Math::CoordF intersection, float dt) {
		if (ent->getID() == enemy) {
			Entities::Characters::Character* pChar = dynamic_cast<Entities::Characters::Character*>(ent);
			if (pChar) {
				pChar->takeDamage(damage * dt);
			}
		}
	}
	MachineGun::MachineGun(EntitiesList* list, Entities::Characters::Player* user) : Entity(Math::CoordF(400, 200), Math::CoordF(MACHINE_GUN_SIZE_X, MACHINE_GUN_SIZE_Y), weapon),
		user(user),
		list(list)
	{
		if (body) {
			body->setFillColor(sf::Color::Yellow);
		}
		if(user->isFacingLeft())
			position.x = user->getPosition().x - (user->getSize().x / 2 + size.x / 2);
		else
			position.x = user->getPosition().x + user->getSize().x / 2 + size.x / 2;
		position.y = user->getPosition().y;
		bullet = new MachineGun::Bullet(Math::CoordF(0, 0), this);
		if (list) {
			list->setData(this);
			list->setData(bullet);
		}
	}
	MachineGun::~MachineGun() {
		/*if (bullet) {
			list->removeData(bullet);
			delete bullet;
		}*/
	}
	MachineGun::Bullet* MachineGun::getBullet() {
		return bullet;
	}
	void MachineGun::execute(float dt) {
		update(dt);
		bullet->followPlayer(user->isFacingLeft());
		body->setPosition(position.x, position.y);
	}
	void MachineGun::update(float dt) {
		if (user->isFacingLeft())
			position.x = user->getPosition().x - (user->getSize().x / 2 + size.x / 2);
		else
			position.x = user->getPosition().x + user->getSize().x / 2 + size.x / 2;
		position.y = user->getPosition().y;
	}
	void MachineGun::shoot() {
		bullet->setIsActive(true);
	}
	void MachineGun::stopShoot() {
		bullet->setIsActive(false);
	}
	void MachineGun::collide(Entity* ent, Math::CoordF intersection, float dt) {}
}
