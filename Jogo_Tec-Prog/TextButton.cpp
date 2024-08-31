#include "TextButton.h"

namespace Menu {
	namespace Button {
		TextButton::TextButton(const std::string info, const sf::Vector2f size, const sf::Vector2f pos, const ID id, const sf::Color selectedColor) :
			Button(size, pos, id), selectedColor(selectedColor),
			text(pGraphic->loadFont("yoster.ttf"), info), selected(false)
		{
			sf::Vector2f textSize = this->text.getSize();
			sf::Vector2f textPos = sf::Vector2f(
				pos.x + size.x / 2.0f - textSize.x / 2.05f,
				pos.y + size.y / 2.0f - textSize.y * 1.2f
			);
			this->text.setPos(textPos);
		}

		TextButton::~TextButton() {

		}

		const sf::Vector2f TextButton::getTextSize() const {
			return sf::Vector2f(text.getText().getGlobalBounds().width, text.getText().getGlobalBounds().height);
		}

		void TextButton::render() {
			pGraphic->render(text.getText());
		}

		void TextButton::setSelected(bool selected) {
			text.setTextColor(selected ? selectedColor : sf::Color::White);
			this->selected = selected;
		}

		const bool TextButton::getSelected() const {
			return selected;
		}
	}
}