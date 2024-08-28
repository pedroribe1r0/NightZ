#include "Background.h"

namespace GraphicalElements {
	namespace Parallax {
		Background::Background() :
			Ente(background), prevCameraPos(pGraphic->getCenterView()), layers(), grass(nullptr)
		{
			
		}

		Background::~Background() {
			for (int i = 0; i < layers.size(); i++) {
				Layer* layer = layers.at(i);
				if (layer) {
					delete(layer);
					layer = nullptr;
				}
			}
			layers.clear();
			delete grass;
			grass = nullptr;
		}

		void Background::render() {
			for (int i = 0; i < layers.size(); i++) {
				Layer* layer = layers.at(i);
				if (layer->getID() != floor) {
					layer->renderLayer();
				}
			}
		}

		void Background::addLayer(const char* texturePath, const float speed, LID id) {
			Layer* layer = new Layer(pGraphic->loadTexture(texturePath), speed, id);
			if (layer == nullptr) {
				std::cout << "ERROR: GraphicalElements::Parallax::Background: not possible to create layer" << std::endl;
				exit(1);
			}
			if (layer->getID() == floor)
				grass = layer;
			layers.push_back(layer);
		}
		
		void Background::update(float dt) {
			sf::Vector2f cameraPos = pGraphic->getCenterView();
			sf::Vector2f ds = cameraPos - prevCameraPos;
			prevCameraPos = cameraPos;
			for (int i = 0; i < layers.size(); i++) {
				layers.at(i)->update(ds, cameraPos);
			}
		}
		void Background::run() {
			update(0);
			render();
		}
		void Background::renderFloor() {
			grass->renderLayer();
		}
	}
}