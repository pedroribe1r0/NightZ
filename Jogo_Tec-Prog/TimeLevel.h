#pragma once
#include "RoundLevel.h"
namespace States {
	namespace Levels {
		class TimeLevel : public Level
		{
		private:
			float finalTime;
			float currentTime;
		public:
			TimeLevel();
			~TimeLevel();
			void run();
			void render();
			void execute(float dt);
			void createMud();
			void createThrowers();
			void spawnEnemies();
		};
	}
}

