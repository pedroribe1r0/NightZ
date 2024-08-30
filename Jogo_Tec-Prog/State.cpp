#include "State.h"

namespace States {
	State::State(const stateID id) :
		Ente(), remove(false) 
	{

	}

	State::~State() {

	}

	void State::render() {

	}

	void State::setRemove(const bool remove) {
		this->remove = remove;
	}

	const bool State::getRemove() const {
		return remove;
	}

}