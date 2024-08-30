#pragma once
#include "State.h"
#define STATES_NUMBER 7
namespace States {
	class StateMachine
	{
	private:
		std::stack<State*> statesStack;

		//Singleton
		StateMachine();
		static StateMachine* pMachine;
	public:
		static StateMachine* getInstance();
		~StateMachine();
		void pushState(State* s);
		void popState();
		void renderState();
		void executeState(float dt);
		void manageCollision(float dt);
	};
}

