#pragma once
#include "Level.h"
namespace States {
	namespace Levels {
		class RoundLevel : public Level
		{
		private:
			int currentRound;
			int finalRound;
			int currentEnemies;
			int deadEnemies;
			float currentTime;
			int nonEnemies;
		public:
			RoundLevel(bool player2);
			~RoundLevel();
			void render();
			void execute(float dt);
			void createBosses();
			void createBonfires();
			void spawnEnemies();
		};
	}
}

