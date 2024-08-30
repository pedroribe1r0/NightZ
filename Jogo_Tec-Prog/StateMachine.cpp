/*#include "StateMachine.h"
#include <iostream>

namespace State {

    StateMachine::StateMachine() {
        lastStateID = stateID::unknown;
        currentStateID = stateID::unknown;
    }

    StateMachine::~StateMachine() {
        std::map<stateID, States*>::iterator it;

        for (it = mapOfStates.begin(); it != mapOfStates.end(); ++it) {
            delete (it->second);
        }
    }

    void StateMachine::changeCurrentState(State::stateID id) {
        lastStateID = currentStateID;
        currentStateID = id;
        mapOfStates[currentStateID]->resetState();
    }

    void StateMachine::updateCurrentState(const float dt) {
        mapOfStates[currentStateID]->update(dt);
    }

    void StateMachine::renderCurrentState() {
        mapOfStates[currentStateID]->render();
    }

    stateID StateMachine::getCurrentStateID() const {
        return currentStateID;
    }

    void StateMachine::insertState(State::States* pState) {
        if (pState == nullptr) {
            std::cout << "ERROR pointer to State NULL on StateMachine::insertState()" << std::endl;
            exit(1);
        }
        mapOfStates.insert(std::pair<stateID, States*>(pState->getID(), pState));
    }

    State::stateID StateMachine::getLastStateID() const {
        return lastStateID;
    }

}*/