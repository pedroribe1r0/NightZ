#include "Layer.h"

namespace GraphicalElements {
	namespace Parallax {
		Layer::Layer(/*Math::CoordU windowSize*/const sf::Vector2f windowSize, sf::Texture texture, const float speed) :
			windowSize(windowSize), texture(texture), dimension(0, 0, 0, 0), speed(speed)
		{
			dimension.width = -fabs(texture.getSize().x);
			dimension.height = texture.getSize().y;
			dimension.left = texture.getSize().x;

			background.setSize(windowSize);
			background.setTexture(&this->texture);
			background.setPosition(0.0f, 0.0f);

			auxBackground.setSize(windowSize);
			auxBackground.setTexture(&this->texture);
			auxBackground.setPosition(windowSize.x, 0.0f);
		}

		Layer::~Layer() {}

		void Layer::switchTexture() {
			sf::RectangleShape trocar = background;
			background = auxBackground;
			auxBackground = trocar;
		}

		void Layer::renderLayer(sf::RenderWindow* window) {
			pGraphic->render();
			if (speed != 0.0f) {
				window->draw(auxBackground);
			}
		}

		void Layer::update(const sf::Vector2f ds, const sf::Vector2f currentCameraPos) {
			const float rightPos = currentCameraPos.x + windowSize.x / 2.0f;
			const float leftPos = currentCameraPos.x - windowSize.x / 2.0f;

			if (speed != 0.0f) {
				const sf::Vector2f backgroundPos = background.getPosition();
				const sf::Vector2f auxBackgroundPos = auxBackground.getPosition();

				background.move(ds.x * -speed, 0.0f);
				auxBackground.move(ds.x * -speed, 0.0f);

				if (ds.x > 0.0f) {
					if (backgroundPos.x + windowSize.x < leftPos) {
						switchTexture();
						background.setPosition(leftPos, 0.0f);
						auxBackground.setPosition(rightPos, 0.0f);
					}
				}

				else {
					if (backgroundPos.x > leftPos) {
						switchTexture();
						background.setPosition(leftPos - windowSize.x, 0.0f);
						auxBackground.setPosition(leftPos - windowSize.x, 0.0f);
					}
				}
			}
			else {
				background.setPosition(leftPos, 0.0f);
			}
		}
	}
}