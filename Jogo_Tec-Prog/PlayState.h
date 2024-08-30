#include "MenuState.h"

namespace States {

	class PlayState : public State	{
	private:
		std::map<States::stateID, Levels::Level*> levelMap;
		States::stateID currentLevelID;
	public:
		PlayState(const States::stateID id);
		~PlayState();
		void createLevel();
		std::map<States::stateID, Levels::Level*> getLevelMap();
		const States::stateID getCurrentLevelID() const;
		Levels::Level* getLevel();
		void changeLevel(const States::stateID id);
		void changeObserverState();
		void run();
	};

}