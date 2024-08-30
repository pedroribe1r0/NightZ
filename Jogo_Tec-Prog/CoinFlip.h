#pragma once
#include "Level.h"
namespace States {
	namespace Levels {
		class CoinFlip : public Level
		{
		public:
			CoinFlip();
			~CoinFlip();
			void run();
			void render();
			void execute(float dt);
		};
	}
}

