/*#include "States.h"
#include "StateMachine.h"

namespace State {

    States::States(StateMachine* pStateM, State::stateID id) :
        pStateM(pStateM),
        id(id) { }

    States::~States() {
        pStateM = nullptr;
    }

    void States::setStateMachine(StateMachine* pStateM) {
        this->pStateM = pStateM;
    }

    void States::changeState(State::stateID id) {
        pStateM->changeCurrentState(id);
    }

    State::stateID States::getID() const {
        return id;
    }

}*/