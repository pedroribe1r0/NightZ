#pragma once
#include "EntitiesList.h"

namespace Entities {
	#define MACHINE_GUN_SIZE_X 20.0f
	#define MACHINE_GUN_SIZE_Y 10.0f
	#define BULLET_RANGE 200.0f
	#define BULLET_DAMAGE 60.0f
	class MachineGun : public Entity
	{
	private:
		class Bullet : public Entity {
		private:
			float damage;
			MachineGun* gun;
		public:
			Bullet(Math::CoordF pos = Math::CoordF(0, 0), MachineGun* gun = nullptr);
			~Bullet();
			void execute(float dt);
			void update(float dt);
			void collide(Entity* ent, Math::CoordF intersection, float dt);
			void followPlayer(bool left);
		};
		Bullet* bullet;
		Entities::Characters::Player* user;
		EntitiesList* list;
	public:
		MachineGun(EntitiesList* list = nullptr, Entities::Characters::Player* user = nullptr);
		~MachineGun();
		Bullet* getBullet();
		void shoot();
		void stopShoot();
		void collide(Entity* ent, Math::CoordF intersection, float dt);
		void execute(float dt);
		void update(float dt);
	};
}

