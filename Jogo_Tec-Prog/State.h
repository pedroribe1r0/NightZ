#pragma once
#include "EventsManager.h"
namespace States {
	class StateMachine;
	class State : public Ente
	{
	private:
		static StateMachine* pMachine;
		bool isActive;
	public:
		State(ID id = ID::empty);
		virtual ~State();
		void setIsActive(bool iA);
		bool getIsActive();
		virtual void manageCollisions(float dt) = 0;
		virtual void render() = 0;
		virtual void execute(float dt) = 0;
	};
}

