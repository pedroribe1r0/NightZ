#include "Ente.h"

namespace GraphicalElements {
	enum LID {
		empty,
		floor = 1
	};
	namespace Parallax {
		class Background;
		class Layer {
		private:
			const sf::Vector2f windowSize;
			sf::IntRect dimension;
			static Managers::GraphicManager* pGraphic;
			const float speed;

			sf::Texture* texture;
			sf::RectangleShape background;
			sf::RectangleShape auxBackground;
			LID id;

			void switchTexture();
		public:
			Layer(sf::Texture* texture, const float speed, LID id);
			~Layer();
			void renderLayer();
			void update(const sf::Vector2f ds, const sf::Vector2f currentCameraPos);
			LID getID() const;
		};
	}
}