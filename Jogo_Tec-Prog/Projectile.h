#pragma once
#include "Thrower.h"

namespace Entities {
	#define PROJECTILE_SIZE_X 5.0f
	#define PROJECTILE_SIZE_Y 5.0f
	#define PLAYER_PROJECTILE_DAMAGE 70.0f
	#define THROWER_PROJECTILE_DAMAGE 20.0f
	#define PROJECTILE_SPEED 500.0f
	#define THROW_SPEED -300.0f
	#define TIME_MAX 4.0f
	class Projectile : public MovingEntity
	{
	private:
		bool canShoot;
		float range;
		float fireTimer;
		Characters::Character* user;
	public:
		Projectile(Characters::Character* user);
		~Projectile();
		bool shoot(bool left);
		bool getCanShoot() const;
		void setCanShoot(bool canShoot);
		float getRange() const;
		void execute(float dt);
		void update(float dt);
		Characters::Character* getUser() const;
		//void updateRange(Characters::Player* p);
		void collide(Entity* ent, Math::CoordF intersection, float dt);
		void setTextures();
	};
}

