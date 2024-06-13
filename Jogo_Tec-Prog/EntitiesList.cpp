#include "EntitiesList.h"

EntitiesList::EntitiesList() : List(){}
EntitiesList::~EntitiesList() {}
void EntitiesList::update(float dt) {
	Node<Entities::Entity>* aux = head;
	while (aux != NULL) {
		aux->getData()->update(dt);
		aux = aux->next;
	}
}
void EntitiesList::render() {
	Node<Entities::Entity>* aux = head;
	while (aux != NULL) {
		aux->getData()->render();
		aux = aux->next;
	}
}