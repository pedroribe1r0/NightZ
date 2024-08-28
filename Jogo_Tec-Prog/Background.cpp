#include "Background.h"

namespace GraphicalElements {
	namespace Parallax {
		Background::Background() :
			Ente(background), prevCameraPos(pGraphic->centerView(0.0f))/*getCamera()->getCenter())*/, layers()
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
		}

		void Background::render() {
			for (int i = 0; i < layers.size(); i++) {
				Layer* layer = layers.at(i);
				//layer->renderLayer();
			}
		}

		void Background::addLayer(const char* texturePath, const float speed) {
			Layer* layer = new Layer(pGraphic->getWindowSize()/*(sf::Vector2f)pGraphic->getWindow()->getSize()) */ , pGraphic->loadTexture(texturePath), speed);
			if (layer == nullptr) {
				std::cout << "ERROR: GraphicalElements::Parallax::Background: not possible to create layer" << std::endl;
				exit(1);
			}
			layers.push_back(layer);
		}
		
		void Background::updatePosition() {
			sf::Vector2f cameraPos = /* pGraphic->getCamera()->getCenter()*/;
			sf::Vector2f ds = cameraPos - prevCameraPos;
			prevCameraPos = cameraPos;
			for (int i = 0; i < layers.size(); i++) {
				layers.at(i)->update(ds, cameraPos);
			}
		}
		void Background::run() {
			updatePosition();
			render();
		}
	}
}