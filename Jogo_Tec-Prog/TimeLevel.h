#pragma once
#include "RoundLevel.h"
namespace Menu {
	namespace Button {
		class Text;
	}
}
namespace States {
	namespace Levels {
		class TimeLevel : public Level
		{
		private:
			float finalTime;
			float currentTime;
		public:
			TimeLevel(bool player2 = false, bool load = false);
			~TimeLevel();
			void render();
			void execute(float dt);
			void createMud();
			void createThrowers();
			void spawnEnemies();
			void loadLevel();
			void saveLevel();
		};
	}
}

