#include "GraphicManager.h"

namespace Managers {
	GraphicManager* GraphicManager::pGraphic = nullptr;
	float GraphicManager::dt = 0;

	GraphicManager::GraphicManager() : camera(sf::Vector2f(WIDTH/2, HEIGHT/2), sf::Vector2f(WIDTH, HEIGHT)){
		window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Game");
		window->setView(camera);
		clock.restart();
		dt = clock.getElapsedTime().asSeconds();
	}

	GraphicManager* GraphicManager::getInstance() {
		if (pGraphic == nullptr) {
			pGraphic = new GraphicManager();
		}
		return pGraphic;
	}

	/*void GraphicManager::render(std::string textPath, Math::CoordF position, Math::CoordF size) {
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
	}*/

	void GraphicManager::render(sf::RectangleShape* body) {
		window->draw(*body);
	}
	void GraphicManager::render(sf::Sprite* sprite) {
		window->draw(*sprite);
	}
	void GraphicManager::display() {
		if(isWindowOpen())
			window->display();
	}
	void GraphicManager::clear() {
		if(isWindowOpen())
			window->clear();
	}
	GraphicManager::~GraphicManager() {
		for (auto& pair : textures) {
			delete pair.second;
		}
		if (window)
			delete window;
	}
	bool GraphicManager::isWindowOpen() const{
		return window->isOpen();
	}
	void GraphicManager::closeWindow() {
		if(isWindowOpen())
			window->close();
	}
	void GraphicManager::centerView(Math::CoordF pos) {
		camera.setCenter(sf::Vector2f(pos.x, pos.y));
		window->setView(camera);
	}
	sf::Texture* GraphicManager::loadTexture(std::string path) {
		if (textures.count(path) > 0)
			return textures[path];
		sf::Texture* text = new sf::Texture();
		if (!text->loadFromFile(path)) {
			std::cout << "Erro: Textura nao encontrada" << std::endl;
			return nullptr;
		}
		textures.emplace(path, text);
		return text;
	}
	void GraphicManager::updateDeltaTime() {
		dt = clock.getElapsedTime().asSeconds();
		clock.restart();
	}

	Math::CoordU GraphicManager::getWindowSize() const{
		sf::Vector2u size = window->getSize();
		return Math::CoordU(size.x, size.y);
	}

	float GraphicManager::getDeltaTime() const {
		return dt;
	}

	bool GraphicManager::pollEvent(sf::Event& e) {
		return window->pollEvent(e);
	}
}