#include "GraphicManager.h"

namespace Managers {
	GraphicManager* GraphicManager::pGraphic = nullptr;
	float GraphicManager::dt = 0;

	GraphicManager::GraphicManager() {
		window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Game");
		//window->setView(camera);
		clock.restart();
		dt = clock.getElapsedTime().asSeconds();
	}

	GraphicManager* GraphicManager::getInstance() {
		if (pGraphic == nullptr) {
			pGraphic = new GraphicManager();
		}
		return pGraphic;
	}

	void GraphicManager::render(std::string textPath, Math::CoordF position, Math::CoordF size) {
		if (textures.count(textPath) == 0) {
			std::cout << "Erro: textura nao carregada" << std::endl;
			return;
		}
		sf::Texture* text = textures[textPath];
		sf::RectangleShape body;

		body.setSize(sf::Vector2f(size.x, size.y));
		body.setTexture(text);
		body.setPosition(sf::Vector2f(position.x, position.y));

		window->draw(body);
	}

	void GraphicManager::display() {
		window->display();
	}
	void GraphicManager::clear() {
		window->clear();
	}
	GraphicManager::~GraphicManager() {

	}
	bool GraphicManager::isWindowOpen() {
		return window->isOpen();
	}
	void GraphicManager::closeWindow() {
		window->close();
	}
	void GraphicManager::centerView(Math::CoordF pos) {
		camera.setCenter(sf::Vector2f(pos.x, pos.y));
	}
	bool GraphicManager::loadTexture(std::string path) {
		if (textures.count(path) > 0)
			return true;
		sf::Texture* text = new sf::Texture();
		if (!text->loadFromFile(path)) {
			std::cout << "Erro: Textura nao encontrada" << std::endl;
			return false;
		}
		textures.emplace(path, text);
		return true;

	}
	void GraphicManager::updateDeltaTime() {
		dt = clock.getElapsedTime().asSeconds();
	}
}