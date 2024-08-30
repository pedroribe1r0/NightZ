#include "State.h"
#include "StateMachine.h"
namespace States {
	StateMachine* State::pMachine = StateMachine::getInstance();
	State::State(ID id) : Ente(id) {
		pMachine->pushState(this);
		isActive = true;
	}
	State::~State() {
	}
	bool State::getIsActive() {
		return isActive;
	}
	void State::setIsActive(bool iA) {
		isActive = iA;
	}
}