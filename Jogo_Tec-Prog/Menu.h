#pragma once
#include<list>
#include "TextButton.h"

namespace Observers {
	class MenuObserver;
}

namespace Menu {
	class Menu : public States::State
	{
	protected:
		Observers::MenuObserver* menuObserver;
		std::list<Button::TextButton*> textButtonList;
		std::list<Button::TextButton*>::iterator it;
		const sf::Vector2f buttonSize;
		const sf::Vector2f windowSize;
		Button::Text title;
		//bool mouseSelected;

		virtual void createButtons() = 0;
		void initializeIterator();
	public:
		Menu(const ID id, const sf::Vector2f buttonSize, const std::string name, const unsigned int fontSize);
		~Menu();
		void addButton(const std::string info, const sf::Vector2f pos, const ID id, const sf::Color selectedColor);
		//void changeObserverState();
		void selectAbove();
		void selectBelow();
		virtual void selectRight() {};
		virtual void selectLeft() {};
		const ID getSelectedButtonID() const;
		//void mouseEvent(const sf::Vector2f mousePos);
		//const bool getMouseSelected() const;
		virtual void render(); //desenha os botões
		virtual void setIsActive(bool iA);
		virtual bool getIsActive();
	};
}