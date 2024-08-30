#pragma once
#include "EventsManager.h"
#include "Background.h"

namespace Levels {

	class Level : public Ente
	{
	#define SPAWN_TIME 10.0f
	protected:
		static Managers::EventsManager* pEvent;
		Managers::CollisionManager* pColision;
		EntitiesList* staticEntities;
		EntitiesList* movingEntities;
		float spawnTime;
		Math::CoordF spots[10];
		GraphicalElements::Parallax::Background background;
	public:
		Level();
		~Level();
		virtual void run() = 0;
		virtual void execute(float dt) = 0;
		void createLevel();
		void manageCollisions(float dt);
		void createThrowers();
		void createZombies();
		void createBosses();
		void createJumpers();
		void createPortals();
		void spawnEnemies();
		void setRandSpots();
		void createBackground();
		void createPlayers(bool Player2);
	};
}

