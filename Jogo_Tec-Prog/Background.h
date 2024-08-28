#pragma once
#include "Ente.h"
#include "Layer.h"

namespace GraphicalElements {
	namespace Parallax {
		class Background : public Ente {
		private:
			sf::Vector2f prevCameraPos;
			std::vector<Layer*> layers;
		public:
			Background();
			~Background();
			void render();
			void addLayer(const char* texturePath, const float speed);
			void updatePosition();
			void run();
		};
	}
}