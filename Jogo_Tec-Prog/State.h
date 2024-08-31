#pragma once
#include "EventsManager.h"
namespace States {
	class StateMachine;
	class State : public Ente
	{
	protected:
		static StateMachine* pMachine;
	public:
		State(ID id = ID::empty);
		virtual ~State();
		virtual void setIsActive(bool iA);
		virtual bool getIsActive();
		virtual void manageCollisions(float dt);
		virtual void render() = 0;
		virtual void execute(float dt) = 0;
		
	};
}

