#pragma once
#include "EntitiesList.h"

namespace Entities {
	#define MACHINE_GUN_SIZE_X 20.0
	#define MACHINE_GUN_SIZE_Y 10.0
	#define BULLET_RANGE 200.0
	#define BULLET_DAMAGE 100.0
	class MachineGun : public Entity
	{
	private:
		class Bullet : public Entity {
		private:
			int damage;
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

