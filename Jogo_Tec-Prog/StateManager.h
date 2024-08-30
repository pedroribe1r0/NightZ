#pragma once
#include "State.h"
#include<stack>

namespace Managers {
	class StateManager {
	private:
		std::stack<States::State*> stateStack;
		static StateManager* pStateM;
		StateManager();
		
		void disableObservers();
		void activateObservers();
	public:
		~StateManager();
		static StateManager* getInstance();
		void run();
		States::State* getState(const int qttRemove);
		void addState(const States::stateID id);
		void removeState(const int qtt);
		void removeState();
		States::State* getCurrentState();
	};
}