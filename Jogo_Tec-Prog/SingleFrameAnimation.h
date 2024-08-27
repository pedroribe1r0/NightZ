#pragma once
#include <SFML/Graphics.hpp>
#include "Coord.h"
#include "Animation.h"

namespace GraphicalElements {
	class SingleFrameAnimation
	{
	private: 
		sf::Texture* texture;
		sf::RectangleShape body;
		static Managers::GraphicManager* pGraphic;

	public:
		SingleFrameAnimation(const char* path, Math::CoordF position, Math::CoordF size, float scale);

		virtual ~SingleFrameAnimation();

		//void initialize(const char* path, Math::CoordF position, Math::CoordF size, float scale);

		void update(Math::CoordF position);
		void render();
	};
}
