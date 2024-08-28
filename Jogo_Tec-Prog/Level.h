#pragma once
#include "EventsManager.h"
namespace Levels {
	class Level : public Ente
	{
	#define SPAWN_TIME 10.0f
	protected:
		static Managers::EventsManager* pEvent;
		Managers::CollisionManager* pColision;
		EntitiesList* staticEntities;
		EntitiesList* movingEntities;
		int enemiesCounter;
		float spawnTime;
		Math::CoordF spots[10];
	public:
		Level();
		~Level();
		virtual void execute() = 0;
		void manageCollisions(float dt);
		void createThrowers();
		void createZombies();
		void createBosses();
		void spawnEnemies();
		void setRandSpots();
	};
}

