#include "EntitiesList.h"

EntitiesList::EntitiesList() : entitiesList(){}
EntitiesList::~EntitiesList() {

}
void EntitiesList::update(float dt) {
	List<Entities::Entity>::iterator it = entitiesList.begin();
	while (it != entitiesList.end()) {
		(*it)->update(dt);
		it.operator++();
	}
}
	
void EntitiesList::render() {
	List<Entities::Entity>::iterator it = entitiesList.begin();
	while (it != entitiesList.end()) {
		if ((*it)->getIsActive()) {
			(*it)->render();
		}
		it.operator++();
	}
}

void EntitiesList::execute(float dt) {
	List<Entities::Entity>::iterator it = entitiesList.begin();
	while (it != entitiesList.end()) {
		if ((*it)->getIsActive()) {
			(*it)->execute(dt);
		}
		if ((*it)->getID() == player || (*it)->getID() == enemy) {
			Entities::Characters::Character* pChar = dynamic_cast<Entities::Characters::Character*>(*it);
			if (!pChar->getIsAlive()) {
				removeData(pChar);
			}
		}
		it.operator++();
	}
}
void EntitiesList::notifyPlayerDeath(bool isPlayer1) {
	List<Entities::Entity>::iterator it = entitiesList.begin();
	while (it != entitiesList.end()) {
		if (*it) {
			if ((*it)->getID() == enemy) {
				Entities::Characters::Enemy* pE = dynamic_cast<Entities::Characters::Enemy*>(*it);
				if (isPlayer1)
					pE->setPlayer1(nullptr);
				else {
					pE->setPlayer2(nullptr);
				}
			}
		}
		it.operator++();
	}
}
void EntitiesList::setData(Entities::Entity* pEnt) {
	entitiesList.push_back(pEnt);
}
void EntitiesList::removeData(Entities::Entity* pEnt) {
	entitiesList.removeNode(pEnt);
	delete pEnt;
}
int EntitiesList::getSize() const {
	return entitiesList.getSize();
}
List<Entities::Entity>::iterator EntitiesList::begin() {
	return entitiesList.begin();
}
List<Entities::Entity>::iterator EntitiesList::end() {
	return entitiesList.end();
}