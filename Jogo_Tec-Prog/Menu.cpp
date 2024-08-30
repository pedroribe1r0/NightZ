#include "Menu.h"

namespace Menu {
	Menu::Menu(const ID id, const sf::Vector2f buttonSize, const std::string name, const unsigned int fontSize) :
		Ente(id), textButtonList(), it(), buttonSize(),
		windowSize(sf::Vector2f(pGraphic->getWindowSize().x, pGraphic->getWindowSize().y)),
		title(pGraphic->loadFont("yoster.ttf"), name, fontSize),
		menuObserver(new Observers::MenuObserver(this)), mouseSelected(false) 
	{
		if (menuObserver == nullptr) {
			std::cout << "ERROR::Menu::MainMenu:: not possible to create observer to main menu" << std::endl;
			exit(1);
		}
	}

	Menu::~Menu() {
		if (!textButtonList.empty()) {
			for (it = textButtonList.begin(); it != textButtonList.end(); it++) {
				delete(*it);
				*it = nullptr;
			}
			textButtonList.clear();
		}
		if (menuObserver) {
			delete(menuObserver);
			menuObserver = nullptr;
		}
	}

	/*
	void Menu::changeObserverState()
	void Menu::mudarEstadoObservador(){
            observadorMenu->mudarEstadoAtivar();
        }
	*/

	void Menu::addButton(const std::string info, const sf::Vector2f pos, const Button::buttonID id, const sf::Color selectedColor) {
		Button::TextButton* button = new Button::TextButton(info, buttonSize, pos, id, selectedColor);
		if (button == nullptr) {
			std::cout << "ERROR::Menu:: not possible to create button" << std::endl;
			exit(1);
		}
		textButtonList.push_back(button);
	}

	void Menu::initializeIterator() {
		try {
			it = textButtonList.begin();
			(*it)->setSelected(true);
		} catch (const std::exception& e) 
		{
			std::cerr << e.what() << std::endl;
			exit(1);
		}
	}

	void Menu::selectAbove() {
		Button::TextButton* button = *it;
		button->setSelected(false);
		if (it == textButtonList.begin()) {
			it = textButtonList.end();
		}
		it--;
		button = *it;
		button->setSelected(true);
	}

	void Menu::selectBelow() {
		Button::TextButton* button = *it;
		button->setSelected(false);
		it++;
		if (it == textButtonList.end()) {
			it = textButtonList.end();
		}
		button = *it;
		button->setSelected(true);
	}

	const ID Menu::getSelectedButtonID() const {
		return (*it)->getID();
	}

	void Menu::mouseEvent(const sf::Vector2f mousePos) {
		std::list<Button::TextButton*>::iterator aux;
		mouseSelected = false;

		for (aux = textButtonList.begin(); aux != textButtonList.end(); aux++) {
			Button::TextButton* button = *aux;
			sf::Vector2f buttonPos = button->getPos();
			sf::Vector2f cameraPos = pGraphic->getCenterView();
			if (mousePos.x + cameraPos.x - windowSize.x / 2.0f > buttonPos.x && mousePos.x + cameraPos.x - windowSize.x / 2.0f < buttonPos.x + buttonSize.x &&
				mousePos.y + cameraPos.y - windowSize.y / 2.0f > buttonPos.y && mousePos.y + cameraPos.y - windowSize.y / 2.0f < buttonPos.y + buttonSize.y) {
				(*it)->setSelected(false);
				it = aux;
				(*it)->setSelected(true);
				mouseSelected = true;
				break;
			}
		}
	}

	const bool Menu::getMouseSelected() const {
		return mouseSelected;
	}

	void Menu::render() {
		std::list<Button::TextButton*>::iterator aux;
		for (aux = textButtonList.begin(); aux != textButtonList.end(); aux++) {
			Button::TextButton* button = *aux;
			button->render();
			button = nullptr;
		}
	}

	void Menu::changeObserverState() {

	}
}