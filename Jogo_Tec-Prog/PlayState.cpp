#include "PlayState.h"

namespace States {

	PlayState::PlayState(const States::stateID id) :
		State(id), levelMap(), currentLevelID(States::stateID::empty)
	{

	}

	PlayState::~PlayState() {
		std::map<States::stateID, Levels::Level*>::iterator it = levelMap.begin();
		Levels::Level* level = it->second;
		while (it != levelMap.end()) {
			level = it->second;
			if (level != nullptr) {
				delete(level);
				level = nullptr;
			}
			it++;
		}
		levelMap.clear();
		/*
		pGraphic->setLimiteCamera 
		pGraphic->setLimiteObjeto
		*/
	}

	void PlayState::createLevel() {
		if (id == States::stateID::coinflip_state) {
			Levels::Level* level = static_cast<Levels::Level*>(new Levels::CoinFlip());
			this->currentLevelID = States::stateID::coinflip_state;
			levelMap.insert(std::pair<States::stateID, Levels::Level*>(currentLevelID, level));
		}
	}

	std::map<States::stateID, Levels::Level*> PlayState::getLevelMap() {
		return levelMap;
	}

	const States::stateID PlayState::getCurrentLevelID() const {
		return currentLevelID;
	}
	
	Levels::Level* PlayState::getLevel() {
		return levelMap[currentLevelID];
	}

	void PlayState::changeLevel(const States::stateID id) {
		std::map<States::stateID, Levels::Level*>::iterator it = levelMap.begin();
		const States::stateID previousLevelID = this->currentLevelID;
		while (it != levelMap.end()) {
			if (it->second != nullptr) {
				if (it->first == id) {
					levelMap[currentLevelID]->
					break;
				}
			}


		}
	}

}