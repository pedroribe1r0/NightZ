#pragma once
#include "StateMachine.h"
#include "Background.h"

namespace States {
	namespace Levels {
		class Level : public State
		{
#define SPAWN_TIME 5.0f
		protected:
			static Managers::EventsManager* pEvent;
			Managers::CollisionManager* pColision;
			EntitiesList* staticEntities;
			EntitiesList* movingEntities;
			Math::CoordF spots[10];
			GraphicalElements::Parallax::Background background;
			float spawnTime;
			float enemiesNumber;
		public:
			Level(const ID id);
			~Level();
			virtual void execute(float dt) = 0;
			virtual void render() = 0;
			void createLevel();
			void manageCollisions(float dt);
			void createZombies();
			void createPortals();
			virtual void spawnEnemies() = 0;
			void setRandSpots();
			void createBackground();
			void createPlayers(bool Player2);
			void createJumpers();
		};
	}
}

