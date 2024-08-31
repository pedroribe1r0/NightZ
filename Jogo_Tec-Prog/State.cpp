#include "State.h"
#include "StateMachine.h"
namespace States {
	StateMachine* State::pMachine = StateMachine::getInstance();
	State::State(ID id) : Ente(id) {
		pMachine->pushState(this);
		
	}
	State::~State() {
	}
	bool State::getIsActive() {
		return true;
	}
	void State::setIsActive(bool iA) {
		
	}
	void State::manageCollisions(float dt){}
}