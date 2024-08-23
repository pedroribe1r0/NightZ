#pragma once
#include "PlayerObserver.h"
//O codigo usado de base foi feito por Matheus Augusto Burda(Burda Canal no Youtube)
namespace Managers {
	class InputManager
	{
	private:
		std::list<Observers::Observer*> observers;

		static InputManager* pInput;
		InputManager();
	public:
		static InputManager* getInstance();

		~InputManager();
		void handleKeyPressed(sf::Keyboard::Key key);
		void handleKeyReleased(sf::Keyboard::Key key);
		void addObserver(Observers::Observer* obs);
		void removeObserver(Observers::Observer* obs);
	};
}

