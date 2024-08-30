#include "Text.h"

namespace Menu {
	namespace Button {
		Text::Text(const sf::Font font, const std::string info, const unsigned int fontSize) :
			font(font), text(), info(info), textColor(sf::Color::White),
			borderColor(sf::Color::Black), fontSize(fontSize)
		{
			initialize();
		}

		Text::~Text() {

		}

		void Text::initialize() {
			text.setString(info);
			text.setCharacterSize(fontSize);
			text.setFont(font);
			text.setOutlineThickness(5.0f);
			text.setOutlineColor(borderColor);
			text.setFillColor(textColor);
			size = sf::Vector2f(text.getGlobalBounds().width, text.getGlobalBounds().height);
		}

		void Text::setTextColor(const sf::Color textColor) {
			this->textColor = textColor;
			text.setFillColor(textColor);
		}

		const sf::Text Text::getText() const {
			return text;
		}

		void Text::setPos(const sf::Vector2f pos) {
			this->pos;
			text.setPosition(pos);
		}

		const sf::Vector2f Text::getPos() const {
			return pos;
		}

		const sf::Vector2f Text::getSize() const {
			return size;
		}
	
		void Text::setBorderSize(const float borderSize) {
			text.setOutlineThickness(borderSize);
			size = sf::Vector2f(text.getGlobalBounds().width, text.getGlobalBounds().height);
		}

		void Text::setSpacing(const float spacingSize) {
			text.setLetterSpacing(spacingSize);
			size = sf::Vector2f(text.getGlobalBounds().width, text.getGlobalBounds().height);
		}

		void Text::setString(std::string name) {
			text.setString(name);
			size = sf::Vector2f(text.getGlobalBounds().width, text.getGlobalBounds().height);
		}

		const std::string Text::getString() const {
			return text.getString();
		}

		void Text::setFontSize(const unsigned int fontSize) {
			text.setCharacterSize(fontSize);
			size = sf::Vector2f(text.getGlobalBounds().width, text.getGlobalBounds().height);
		}
	}
}