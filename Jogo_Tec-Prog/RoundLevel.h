#pragma once
#include "Level.h"
namespace Menu {
	namespace Button {
		class Text;
	}
}
namespace States {
	namespace Levels {
		#define ROUND_MAX_TIME 80.0f
		class RoundLevel : public Level
		{
		private:
			int currentRound;
			int finalRound;
			int currentEnemies;
			int deadEnemies;
			float currentTime;
			int nonEnemies;
			float roundTimeCounter;
		public:
			RoundLevel(bool player2 = false, bool load = false);
			~RoundLevel();
			void render();
			void execute(float dt);
			void createBosses();
			void createBonfires();
			void spawnEnemies();
			void loadLevel();
			void saveLevel();
		};
	}
}

