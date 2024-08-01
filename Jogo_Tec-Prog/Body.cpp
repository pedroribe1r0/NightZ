#include "Body.h"

namespace Entities {
	Body::Body() {
		pGraphic = Managers::GraphicManager::getInstance();

		body = new sf::RectangleShape();
	}
	Body::~Body() {
		delete body;
	}
	void Body::setTexture(std::string textPath) {
		body->setTexture(pGraphic->loadTexture(textPath));
	}
	void Body::render() {
		pGraphic->render(body);
	}
	void Body::setSize(Math::CoordF size) {
		body->setSize(sf::Vector2f(size.x, size.y));
		body->setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
	}
	void Body::update(Math::CoordF position) {
		body->setPosition(sf::Vector2f(position.x, position.y));
	}
}
