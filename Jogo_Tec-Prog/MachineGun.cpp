#include "MachineGun.h"

namespace Entities {
	MachineGun::Bullet::Bullet(Math::CoordF pos, MachineGun* gun): Entity(pos, Math::CoordF(BULLET_RANGE, 4.0), ID::empty), gun(gun){
		damage = BULLET_DAMAGE;
		if (body) {
			body->setFillColor(sf::Color::Green);
			//texture
		}
		position.y = gun->getPosition().y;
		position.x = gun->getPosition().x + gun->getSize().x / 2 + size.x / 2;
	}
	MachineGun::Bullet::~Bullet() {
		gun = nullptr;
	}
	void MachineGun::Bullet::execute(float dt) {}
	void MachineGun::Bullet::update(float dt) {}
	void MachineGun::Bullet::followPlayer(bool left) {
		if(left)
			position.x = gun->getPosition().x - (gun->getSize().x / 2 + size.x / 2);
		else
			position.x = gun->getPosition().x + gun->getSize().x / 2 + size.x / 2;
	}
	void MachineGun::Bullet::collide(Entity* ent, Math::CoordF intersection, float dt) {
		if (ent->getID() == enemy) {
			Entities::Characters::Character* pChar = dynamic_cast<Entities::Characters::Character*>(ent);
			if (pChar) {
				pChar->takeDamage(damage * dt);
			}
		}
	}
	MachineGun::MachineGun(Math::CoordF pos, Entities::Characters::Player* user) : Entity(pos, Math::CoordF(MACHINE_GUN_SIZE_X, MACHINE_GUN_SIZE_Y), weapon),
		user(user)
	{
		if(user->isFacingLeft())
			position.x = user->getPosition().x - (user->getSize().x / 2 + size.x / 2);
		else
			position.x = user->getPosition().x + user->getSize().x / 2 + size.x / 2;
		position.y = user->getPosition().y;
		bullet = new MachineGun::Bullet(Math::CoordF(0, 0), this);
	}
	MachineGun::~MachineGun() {

	}
	void MachineGun::execute(float dt) {
		update(dt);
		bullet->followPlayer(user->isFacingLeft());
	}
	void MachineGun::update(float dt) {
		if (user->isFacingLeft())
			position.x = user->getPosition().x - (user->getSize().x / 2 + size.x / 2);
		else
			position.x = user->getPosition().x + user->getSize().x / 2 + size.x / 2;
	}
	void MachineGun::shoot() {
		
	}
	void MachineGun::stopShoot() {
		
	}
	void MachineGun::collide(Entity* ent, Math::CoordF intersection, float dt) {}
}
