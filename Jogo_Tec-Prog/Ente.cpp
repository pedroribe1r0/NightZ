#include "Ente.h"
#include "Player.h"

Managers::GraphicManager* Ente::pGraphic = Managers::GraphicManager::getInstance();

Entities::Characters::Player* Ente::pPlayer1 = nullptr;
Entities::Characters::Player* Ente::pPlayer2 = nullptr;

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

void Ente::setPlayers(Entities::Characters::Player* p1, Entities::Characters::Player* p2) {
	if (p1) {
		pPlayer1 = p1;
	}
	if (p2)
		pPlayer2 = p2;
}

void Ente::setP1Null() {
	pPlayer1 = nullptr;
}
void Ente::setP2Null() {
	pPlayer2 = nullptr;
}
