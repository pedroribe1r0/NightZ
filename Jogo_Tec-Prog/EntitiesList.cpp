#include "EntitiesList.h"

EntitiesList::EntitiesList() : entitiesList(){}
EntitiesList::~EntitiesList() {

}
void EntitiesList::update(float dt) {
	List<Entities::Entity>::iterator aux = entitiesList.begin();
	while (aux != NULL) {
		aux->getData()->update(dt);
		aux = aux->next;
	}
}
void EntitiesList::render() {
	List<Entities::Entity>::iterator aux = entitiesList.begin();
	while (aux != NULL) {
		aux->getData()->render();
		aux = aux->next;
	}
}

void EntitiesList::setData(Entities::Entity* pEnt) {
	entitiesList.setData(pEnt);
}
void EntitiesList::removeData(Entities::Entity* pEnt) {
	List<Entities::Entity>::iterator aux = entitiesList.begin();
	while (aux != NULL && aux->getData() != pEnt) {
		aux = aux->next;
	}
	if (aux != NULL) {
		aux->prev->next = aux->next;
		aux->next->prev = aux->prev;
		delete aux;
		aux = NULL;
	}
}
int EntitiesList::getSize() const {
	return entitiesList.getSize();
}