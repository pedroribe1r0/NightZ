#pragma once
#include <SFML/Graphics.hpp>
#include "Coord.h"
#include <iostream>
#include <map>
#include <string>

namespace Managers {
	class GraphicManager
	{
	private:
		sf::RenderWindow* window;
		sf::View camera;
		std::map<std::string, sf::Texture*> textures;
		sf::Clock clock;
		static float dt;

		static Managers::GraphicManager* pGraphic;
		GraphicManager();
	public:
		static GraphicManager* getInstance();

		void render(std::string textPath, Math::CoordF position, Math::CoordF size);
		void display();
		void clear();
		~GraphicManager();
		bool isWindowOpen();
		void closeWindow();
		void centerView(Math::CoordF pos);
		bool loadTexture(std::string path);
		void updateDeltaTime();
		
	};
}

