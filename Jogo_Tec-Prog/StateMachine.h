/*#pragma once
#include "States.h"
#include <map>

namespace State {

    class StateMachine {
    protected:
        State::stateID currentStateID;
        State::stateID lastStateID;

        std::map<stateID, States*> mapOfStates;

    public:
        StateMachine();

        virtual ~StateMachine();

        void changeCurrentState(State::stateID id);

        void updateCurrentState(const float dt);

        void renderCurrentState();

        State::stateID getCurrentStateID() const;

        void insertState(State::States* pState);

        States::stateID getLastStateID() const;
    };

}*/