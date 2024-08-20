#pragma once
#include <SFML/Graphics.hpp>
#include "Coord.h"
#include <iostream>
#include <unordered_map>
#include <string>

//Inspirado no Gerenciador Grafico do Monitor Matheus Augusto Burda (Burda Canal)

namespace Managers {
	#define WIDTH 1200
	#define HEIGHT 720
	class GraphicManager
	{
	private:
		sf::RenderWindow* window;
		sf::View camera;
		std::unordered_map<std::string, sf::Texture*> textures;
		sf::Clock clock;
		static float dt;

		//singleton
		static Managers::GraphicManager* pGraphic;
		GraphicManager();
	public:
		static GraphicManager* getInstance();

		//void render(std::string textPath, Math::CoordF position, Math::CoordF size);
		void render(sf::RectangleShape* body);
		void display();
		void clear();
		~GraphicManager();
		bool isWindowOpen() const;
		void closeWindow();
		void centerView(Math::CoordF pos);
		sf::Texture* loadTexture(std::string path);
		void updateDeltaTime();
		float getDeltaTime() const;
		Math::CoordU getWindowSize() const;
	};
}

