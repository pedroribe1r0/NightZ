#pragma once
#include <SFML/Graphics.hpp>
#include "Coord.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <list>
//O codigo usado de base foi feito por Matheus Augusto Burda(Burda Canal no Youtube)

namespace Managers {
	#define WIDTH 1280
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
		void render(sf::Sprite* sprite);
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
		bool pollEvent(sf::Event& e);
		sf::Vector2f getCenterView() const;
	};
}

