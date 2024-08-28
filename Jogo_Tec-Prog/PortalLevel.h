#pragma once
#include "CoinFlip.h"
namespace Levels {
	class PortalLevel : public Level
	{
	public:
		PortalLevel();
		~PortalLevel();
		void execute();
		void render();
		void update(float dt);
	};
}

