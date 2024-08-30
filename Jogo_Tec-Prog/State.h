#pragma once
#include "MenuObserver.h"
#include "PortalLevel.h"
#include "CoinFlip.h"

namespace States {

	enum stateID {
		empty = 0,
		gameover_menu_state,
		pause_menu_state,
		saveprogress_menu_state,
		mainmenu_state,
		coinflip_state,
		portal_state
	};

	class State : public Ente {
	private:
		bool remove;
	public:
		State(const stateID id);
		virtual ~State();
		virtual void run() = 0;
		virtual void render();
		void setRemove(const bool remove = true);
		const bool getRemove() const;
		virtual void changeObserverState() = 0;
	};
}

