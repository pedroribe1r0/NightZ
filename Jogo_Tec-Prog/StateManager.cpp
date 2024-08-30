/*#include "StateManager.h"

namespace Managers {
	
	StateManager* StateManager::pStateM = nullptr;

	StateManager::StateManager() :
		stateStack()
	{

	}

	StateManager* StateManager::getInstance() {
		if (pStateM == nullptr) {
			pStateM = new StateManager();
		}
		return pStateM;
	}

	StateManager::~StateManager() {
		while (!stateStack.empty()) {
			delete(stateStack.top());
			stateStack.top() = nullptr;
			stateStack.pop();
		}

		if (pStateM) {
			delete(pStateM);
			pStateM = nullptr;
		}
	}

	void StateManager::activateObservers() {
		States::State* currentState = getCurrentState();
		currentState->changeObserverState();
	}

	void StateManager::addState(const States::stateID id) {
		States::State* state = nullptr;

		if (
			id == States::stateID::mainmenu_state
			//outros stateID's de menus
		   ) 
			{
				state = static_cast<States::State*>(new States::MenuState(id);
			}
		else if (
				 id == play_coinflip ||
				 id == play_portal
			    )
			{
				state = static_cast<States::State*>(new States::PlayState(id));
			}

		if (state == nullptr) {
			std::cout << "ERROR::Managers::StateManager:: state is nullptr" << endl;
			exit(1);
		}
		
		if (!stateStack.empty()) {
			disableObservers();
		}

		stateStack.push(state);
	}

	void StateManager::removeState() {
		if (stateStack.top() != nullptr && !stateStack.empty()) {
			delete(stateStack.top());
			stateStack.top() = nullptr;
			stateStack.pop();
		}
		if (!stateStack.empty()) {
			activateObservers();
		}
		else {
			GraphicManager* pGraphic = pGraphic->getInstance();
			pGraphic->closeWindow();
		}
	}

	States::State* StateManager::getCurrentState() {
		if (!stateStack.empty()) {
			return stateStack.top();
		}
		return nullptr;
	}

	States::State* StateManager::getState(const int qttRemove) {
		std::stack<States::State*> auxStateStack = stateStack;
		int i = 0;
		while (i < qttRemove && !auxStateStack.empty()) {
			auxStateStack.pop();
			i++;
		}
		if (!auxStateStack.empty()) {
			return auxStateStack.top();
		}
		return nullptr;
	}

	void StateManager::run() {
		if (!stateStack.empty()) {
			States::State* state = stateStack.top();
			state->run();
		}
	}

}*/