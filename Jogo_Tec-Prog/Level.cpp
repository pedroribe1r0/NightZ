#include "Level.h"

namespace Levels {
	Managers::EventsManager* Level::pEvent = Managers::EventsManager::getInstance();

	Level::Level() {
		movingEntities = new EntitiesList();
		staticEntities = new EntitiesList();
		pColision = new Managers::CollisionManager(movingEntities, staticEntities);
		enemiesCounter = 0;
		spawnTime = 0;
		setRandSpots();
		createBosses();
		createThrowers();
		createZombies();
	}
	Level::~Level() {
		delete movingEntities;
		delete staticEntities;
		delete pColision;
	}
	void Level::createBackground() {
		background.addLayer("layer11.png", 0.0f, GraphicalElements::LID::empty);
		background.addLayer("layer10.png", 0.0000005f, GraphicalElements::LID::empty);
		background.addLayer("layer9.png", 0.000001f, GraphicalElements::LID::empty);
		background.addLayer("layer8.png", 0.00003f, GraphicalElements::LID::empty);
		background.addLayer("layer7.png", 0.0006f, GraphicalElements::LID::empty);
		background.addLayer("layer6.png", 0.007f, GraphicalElements::LID::empty);
		background.addLayer("layer5.png", 0.008f, GraphicalElements::LID::empty);
		background.addLayer("layer4.png", 0.009, GraphicalElements::LID::empty);
		background.addLayer("layer3.png", 0.05f, GraphicalElements::LID::empty);
		background.addLayer("layer2.png", 0.06f, GraphicalElements::LID::empty);
		background.addLayer("layer1.png", 0.08f, GraphicalElements::LID::empty);
		background.addLayer("layer0.png", 0.1f, GraphicalElements::LID::floor);
	}
	void Level::manageCollisions(float dt) {
		pColision->collide(dt);
	}
	void Level::setRandSpots() {
		spots[0] = Math::CoordF(-1140, 360);
		spots[1] = Math::CoordF(-1640, 600);
		spots[2] = Math::CoordF(-840, 600);
		spots[3] = Math::CoordF(-1840, 600);
		spots[4] = Math::CoordF(-1140, 600);
		spots[5] = Math::CoordF(3200, 360);
		spots[6] = Math::CoordF(1640, 600);
		spots[7] = Math::CoordF(2600, 600);
		spots[8] = Math::CoordF(2300, 600);
		spots[9] = Math::CoordF(3000, 600);
	}
	void Level::createThrowers() {
		srand(time(NULL));
		int cont = 0;
		for (int i = 0; i < 30; i++) {
			if ((rand() % 10)) {
				Entities::Characters::Thrower* t = new Entities::Characters::Thrower(Math::CoordF(-99999, -9999), movingEntities);
				t->setIsActive(false);
				movingEntities->setData(t);
				cont++;
			}
			if (cont < 10 && i == 29)
				i--;
		}
		cout << cont << endl;
		
	}
	void Level::createZombies() {
		srand(time(NULL));
		int cont = 0;
		for (int i = 0; i < 30; i++) {
			if ((rand() % 10)) {
				Entities::Characters::Zombie* t = new Entities::Characters::Zombie(Math::CoordF(-99999, -9999));
				t->setIsActive(false);
				movingEntities->setData(t);
				cont++;
			}
			if (cont < 10 && i == 29)
				i--;
		}
		cout << cont << endl;
	}
	void Level::createBosses() {
		srand(time(NULL));
		int cont = 0;
		for (int i = 0; i < 30; i++) {
			if ((rand() % 10)) {
				Entities::Characters::Boss* t = new Entities::Characters::Boss(Math::CoordF(-99999, -9999));
				t->setIsActive(false);
				movingEntities->setData(t);
				cont++;
			}
			if (cont < 10 && i == 29)
				i--;
		}
		cout << cont << endl;
	}

	void Level::spawnEnemies() {
		/*Entities::Entity* ent = movingEntities->pickRandon();
		while (ent->getID() != enemy) {
			ent = movingEntities->pickRandon();
		}*/
		Entities::Entity* ent = nullptr;
		List<Entities::Entity>::iterator it = movingEntities->begin();
		int i = 0;
		while (it != movingEntities->end()) {
			if ((*it)->getID() == enemy && i > enemiesCounter) {
				ent = (*it);
				break;
			}
			else if ((*it)->getID() == enemy)
				i++;
			++it;
		}
		if (ent) {
			cout << ent->getSize().x << endl;
			if (ent->getID() == enemy) {
				Entities::Characters::Enemy* e = dynamic_cast<Entities::Characters::Enemy*>(ent);
				Entities::Characters::Player* p1 = e->getPlayer1();
				Entities::Characters::Player* p2 = e->getPlayer2();
				int randSpot = 0;
				/*if (p1 && p2) {
					if ((p1->getPosition().x < 80 && p2->getPosition().x > 1360) || (p1->getPosition().x > 80 && p2->getPosition().x < 1360)) {
						randSpot = rand() % 10;
					}
					else if (p1->getPosition().x < 80 && p2->getPosition().x < 80) {
						randSpot = rand() % 5;
					}
					else if (p1->getPosition().x > 1360 && p2->getPosition().x > 1360) {
						randSpot = rand() % 5 + 5;
					}
					else {
						randSpot = rand() % 10;
					}
				}*/
				if (p1) {
					if (p1->getPosition().x < -80) {
						randSpot = rand() % 5;
					}
					else if (p1->getPosition().x > 1360) {
						randSpot = rand() % 5 + 5;
					}
					else {
						randSpot = rand() % 10;
					}
				}
				/*else if (p2) {
					if (p2->getPosition().x < 80) {
						randSpot = rand() % 5;
					}
					else if (p2->getPosition().x > 1360) {
						randSpot = rand() % 5 + 5;
					}
					else {
						randSpot = rand() % 10;
					}
				}*/
				cout << randSpot << endl;
				if(p1)
					cout << p1->getPosition().x << " " << p1->getPosition().y << endl;
				e->setPosition(spots[randSpot]);
				e->setIsActive(true);
				enemiesCounter++;
			}
		}
	}
}