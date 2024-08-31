#pragma once
#include "Button.h"

namespace Menu {
	namespace Button {
		class Text {
		private:
			const sf::Font font;
			std::string info;

		protected:
			sf::Text text;
			sf::Vector2f size;
			sf::Vector2f pos;
			unsigned int fontSize;
			sf::Color textColor;
			sf::Color borderColor;

			void initialize();

		public:
			Text(const sf::Font font, const std::string info, const unsigned int fontSize = 50);
			virtual ~Text();
			const sf::Text getText() const;
			void setPos(const sf::Vector2f pos);
			const sf::Vector2f getPos() const;
			const sf::Vector2f getSize() const;
			void setTextColor(const sf::Color textColor);
			void setBorderSize(const float borderSize);
			void setSpacing(const float spacingSize);
			void setString(std::string name);
			const std::string getString() const;
			void setFontSize(const unsigned int fontSize);
			void setBorderColor(const sf::Color borderColor);
		};
	}
}