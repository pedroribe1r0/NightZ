/*#pragma once
#include "MenuObserver.h"

namespace State {

    class StateMachine;

    enum stateID {
        unknown = -1,
        mainMenu = 0,
        newGame,
        playing,
        pauseMenu,
        settings,
        leaderboard,
        gameOver
    };

    class States {

    protected:
        StateMachine* pStateM;
        stateID id;

    public:
        States(StateMachine* pStateM = nullptr, State::stateID id = unknown);

        virtual ~States();

        void setStateMachine(StateMachine* pStateM);

        void changeState(State::stateID id);

        State::stateID getID() const;

        virtual void update(const float dt) = 0;

        virtual void render() = 0;

        virtual void resetState() = 0;
    };

}*/