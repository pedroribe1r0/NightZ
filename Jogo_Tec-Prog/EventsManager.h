#pragma once
#include "InputManager.h"
//O codigo usado de base foi feito por Matheus Augusto Burda(Burda Canal no Youtube)
namespace Managers {
	class EventsManager
	{
	private:
		GraphicManager* pGraphic;
		InputManager* pInput;
		//singleton
		static EventsManager* pEvent;
		EventsManager();
	public:
		~EventsManager();

		static EventsManager* getInstance();

		void pollEvents();
	};
}

