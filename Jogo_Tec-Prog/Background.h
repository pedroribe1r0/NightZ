#pragma once
#include "Layer.h"

namespace GraphicalElements {
	namespace Parallax {
		class Background : public Ente {
		private:
			sf::Vector2f prevCameraPos;
			std::vector<Layer*> layers;
			Layer* grass;
		public:
			Background();
			~Background();
			void render();
			void addLayer(const char* texturePath, const float speed, LID id);
			void execute(float dt);
			void run();
			void renderFloor();
		};
	}
}