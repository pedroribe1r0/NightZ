#include "Button.h"

namespace Menu {
	namespace Button {
		Button::Button(const sf::Vector2f size, const sf::Vector2f pos, const ID id) :
			Ente(id), size(size), pos(pos), texture(new sf::Texture())
		{
			box.setPosition(pos);
			box.setSize(size);
		}

		Button::~Button(){
			if (texture) {
				delete texture;
				texture = nullptr;
			}
		}

		const sf::Vector2f Button::getPos() const {
			return box.getPosition();
		}

		void Button::setTexture(sf::Texture* texture) {
			this->texture = texture;
			box.setTexture(texture);
		}

		void Button::render() {
			pGraphic->render(&box);
		}

		void Button::execute(float dt) {

		}
	}

}