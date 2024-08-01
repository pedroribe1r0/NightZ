#pragma once
#include "GraphicManager.h"

namespace Entities {
	class Body
	{
	protected:
		sf::RectangleShape* body;

		Managers::GraphicManager* pGraphic;
	public:
		Body();
		~Body();
		void setTexture(std::string textPath);
		void render();
		void update(Math::CoordF position);
		void setSize(Math::CoordF size);

	};
}


