#pragma once
#include "Thrower.h"

namespace Entities {
	#define PROJECTILE_SIZE_X 10
	#define PROJECTILE_SIZE_Y 5
	#define PROJECTILE_DAMAGE 20.0
	#define PROJECTILE_SPEED 200.0
	class Projectile : public MovingEntity
	{
	private:
		bool canShoot;
		float range;
		float damage;
		Characters::Thrower* user;
	public:
		Projectile(Characters::Thrower* user);
		~Projectile();
		void shoot(bool left);
		bool getCanShoot() const;
		void setCanShoot(bool canShoot);
		float getRange() const;
		void execute(float dt);
		void update(float dt);
		void updateRange(Characters::Player* p);
		void collide(Entity* ent, Math::CoordF intersection, float dt);
	};
}

