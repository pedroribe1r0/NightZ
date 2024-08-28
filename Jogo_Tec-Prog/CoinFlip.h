#pragma once
#include "Level.h"
namespace Levels {
	class CoinFlip : public Level
	{
	public:
		CoinFlip();
		~CoinFlip();
		void execute();
		void render();
		void update(float dt);
	};
}

