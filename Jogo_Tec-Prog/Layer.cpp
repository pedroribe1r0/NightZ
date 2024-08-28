#include "Layer.h"

namespace GraphicalElements {
	namespace Parallax {
		Managers::GraphicManager* Layer::pGraphic = Managers::GraphicManager::getInstance();
		Layer::Layer(sf::Texture* texture, const float speed, LID id) :
			texture(texture), dimension(0, 0, 0, 0), speed(speed), windowSize(sf::Vector2f(pGraphic->getWindowSize().x, pGraphic->getWindowSize().y)), id(id)
		{
			dimension.width = -fabs(texture->getSize().x);
			dimension.height = texture->getSize().y;
			dimension.left = texture->getSize().x;
			background.setSize(windowSize);
			background.setTexture(texture);
			background.setPosition(0.0f, 0.0f);

			auxBackground.setSize(windowSize);
			auxBackground.setTexture(texture);
			auxBackground.setPosition(windowSize.x, 0.0f);
		}

		Layer::~Layer() {}

		void Layer::switchTexture() {
			sf::RectangleShape trocar = background;
			background = auxBackground;
			auxBackground = trocar;
		}

		LID Layer::getID() const {
			return id;
		}

		void Layer::renderLayer() {
			pGraphic->render(&background);
			if (speed != 0.0f) {
				pGraphic->render(&auxBackground);
			}
		}

		void Layer::update(const sf::Vector2f ds, const sf::Vector2f currentCameraPos) {
			const float y = currentCameraPos.y - windowSize.y / 2.0f;
			sf::Vector2f backgroundPosition = background.getPosition();
			sf::Vector2f auxBackgroundPosition = auxBackground.getPosition();
			background.setPosition(sf::Vector2f(backgroundPosition.x, y));
			auxBackground.setPosition(sf::Vector2f(auxBackgroundPosition.x, y));
			const float dx = ds.x * 0.5f;
			if (dx != 0.0f) {
				const float rightPos = currentCameraPos.x + windowSize.x / 2.0f;
				const float leftPos = currentCameraPos.x - windowSize.x / 2.0f;
				if (speed != 0.0f) {
					background.move(ds.x * -speed, 0.0f);
					auxBackground.move(ds.x * -speed, 0.0f);
					if (ds.x > 0.0f) {
						if ((backgroundPosition.x + windowSize.x) < leftPos) {
							switchTexture();
							background.setPosition(leftPos, backgroundPosition.y);
							auxBackground.setPosition(rightPos, auxBackgroundPosition.y);
						}
					}
					else {
						if (backgroundPosition.x > leftPos) {
							switchTexture();
							background.setPosition(leftPos - windowSize.x, backgroundPosition.y);
							auxBackground.setPosition(leftPos, auxBackgroundPosition.y);
						}
					}
				}
				else {
					background.setPosition(leftPos, backgroundPosition.y);
				}
			}
			
		}
	}
}