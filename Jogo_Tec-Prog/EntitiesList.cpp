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
		if ((*it)->getID() == player || (*it)->getID() == enemy || (*it)->getID() == boss) {
			Entities::Characters::Character* pChar = dynamic_cast<Entities::Characters::Character*>(*it);
			if (!pChar->getIsAlive()) {
				removeData(pChar);
			}
		}
		it.operator++();
	}
}
Entities::Entity* EntitiesList::pickRandon() {
	int index = rand() % getSize();
	std::cout << index << " index" << endl;
	std::cout << entitiesList.getSize() << " size" << endl;
	List<Entities::Entity>::iterator it = entitiesList.begin();
	for (int i = 0; i < index && it != entitiesList.end(); i++) {
		++it;
	}
	if (*it) {
		return (*it);
	}
	return nullptr;
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