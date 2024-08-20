#include "Ente.h"

Managers::GraphicManager* Ente::pGraphic = Managers::GraphicManager::getInstance();

Ente::Ente(ID id) : id(id) {
	body = new sf::RectangleShape();
}
Ente::~Ente() {
	if (body)
		delete body;
}
void Ente::setID(ID id) {
	this->id = id;
}
ID Ente::getID() const {
	return id;
}
