#pragma once
#include "CoinFlip.h"
namespace Levels {
	class PortalLevel : public Level
	{
	public:
		PortalLevel();
		~PortalLevel();
		void run();
		void render();
		void execute(float dt);
	};
}

