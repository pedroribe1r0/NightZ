#include "Game.h"

namespace GraphicalElements {
	namespace Parallax {
		class Background;
		class Layer {
		private:
			const sf::Vector2f windowSize;
			sf::IntRect dimension;
			Managers::GraphicManager* pGraphic;
			const float speed;

			sf::Texture texture;
			sf::RectangleShape background;
			sf::RectangleShape auxBackground;

			void switchTexture();
		public:
			Layer(/*const* Math::CoordU windowSize* */ const sf::Vector2f windowSize, sf::Texture texture, const float speed);
			~Layer();
			void renderLayer(sf::RenderWindow* window);
			void update(const sf::Vector2f ds, const sf::Vector2f currentCameraPos);
		};
	}
}