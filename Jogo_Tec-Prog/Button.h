#pragma once
#include "PortalLevel.h"

namespace Menu {
	namespace Button {
		
		enum buttonID {
			newgame_button,
			loadgame_button,
			leaderboards_button,
			exit_button,
			coinflip_button,
			portal_button,
			singleplayer,
			multiplayer
		};

		class Button : public Ente
		{
		protected:
			sf::RectangleShape box;
			sf::Texture* texture;
			sf::Vector2f pos;
			sf::Vector2f size;

		public:
			Button(const sf::Vector2f size, const sf::Vector2f pos, const ID id);
			virtual ~Button();
			virtual void render();
			void setTexture(sf::Texture* texture);
			const sf::Vector2f getPos() const;
			void execute(float dt);
		};
	}
}