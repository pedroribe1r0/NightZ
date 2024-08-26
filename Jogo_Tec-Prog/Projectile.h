#pragma once
#include "Thrower.h"

namespace Entities {
	#define PROJECTILE_SIZE_X 10.0f
	#define PROJECTILE_SIZE_Y 10.0f
	#define PROJECTILE_DAMAGE 20.0f
	#define PROJECTILE_SPEED 200.0f
	#define THROW_SPEED -300.0f
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
		//void updateRange(Characters::Player* p);
		void collide(Entity* ent, Math::CoordF intersection, float dt);
	};
}

