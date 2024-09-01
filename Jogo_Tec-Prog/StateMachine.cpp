#include "StateMachine.h"
#include "Menu.h"

namespace States {
	StateMachine* StateMachine::pMachine = nullptr;
	StateMachine* StateMachine::getInstance() {
		if (!pMachine)
			pMachine = new StateMachine();
		return pMachine;
	}
	StateMachine::StateMachine() : statesStack() {
		
	}
	StateMachine::~StateMachine() {
		while (!statesStack.empty()) {
			popState();
		}
	}
	void StateMachine::pushState(State* s) {
		if (!statesStack.empty()) {
			statesStack.top()->setIsActive(false);
		}
		if (s) {
			//s->setIsActive(true);
			statesStack.push(s);
			//cout << s->getID() << endl;
		}
			
	}
	State* StateMachine::getPreviousState() {
		States::State* s = statesStack.top();
		statesStack.pop();
		States::State* s2 = statesStack.top();
		statesStack.push(s);
		return s2;
	}

	void StateMachine::popState() {
		if (!statesStack.empty()) {
			if (statesStack.top()) {
				
				delete statesStack.top();
				statesStack.top() = nullptr;
				statesStack.pop();
				if (!statesStack.empty())
					statesStack.top()->setIsActive(false);
			}
		}
	}
	void StateMachine::popState(int qnt) {
		for (int i = 0; i < qnt; i++) {
			if (!statesStack.empty()) {
				if (statesStack.top()) {
					//cout << statesStack.top()->getID() << endl;
					delete statesStack.top();
					statesStack.top() = nullptr;
					statesStack.pop();
					if (!statesStack.empty())
						statesStack.top()->setIsActive(false);
				}
			}
		}
	}
	void StateMachine::renderState() {
		if (!statesStack.empty()) {
			statesStack.top()->render();
		}
	}
	void StateMachine::executeState(float dt) {
		if (!statesStack.empty()) {
			statesStack.top()->execute(dt);
		}
	}
	void StateMachine::manageCollision(float dt) {
		if (!statesStack.empty()) {
			statesStack.top()->manageCollisions(dt);
		}
	}
	State* StateMachine::getCurrentState() const {
		if (!statesStack.empty())
			return statesStack.top();
		return nullptr;
	}
}
