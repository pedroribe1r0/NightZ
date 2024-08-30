#pragma once
#include "Background.h"

namespace Menu {
	namespace Button {

		enum buttonID {
			newgame_button,
			loadgame_button,
			leaderboards_button,
			exit_button
		};

		class Button : public Ente
		{
		/* BOTÃO ANIMADO
		private:
			const sf::Vector2f maxSize;
			const sf::Vector2f initialSize;
			bool increasing; 
		*/
		protected:
			sf::RectangleShape box;
			sf::Texture* texture;
			sf::Vector2f pos;
			sf::Vector2f size;

			/* BOTÃO ANIMADO:
			const float switchTime;
			float dt;
			*/

		public:
			Button(const sf::Vector2f size, const sf::Vector2f pos, const buttonID id);
			virtual ~Button();
			virtual void render();
			//virtual void updateAnimation(); BOTÃO ANIMADO
			//virtual void updateBoxPosition(); BOTÃO ANIMADO
			void setTexture(sf::Texture* texture);
			const sf::Vector2f getPos() const;
			void execute(float dt);
		};
	}
}