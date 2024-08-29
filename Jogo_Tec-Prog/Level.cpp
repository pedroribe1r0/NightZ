#include "Level.h"

namespace Levels {
	Managers::EventsManager* Level::pEvent = Managers::EventsManager::getInstance();

	Level::Level() {
		srand(time(NULL));
		movingEntities = new EntitiesList();
		staticEntities = new EntitiesList();
		pColision = new Managers::CollisionManager(movingEntities, staticEntities);
		enemiesCounter = 0;
		spawnTime = 0;
		setRandSpots();
		createBosses();
		createThrowers();
		createZombies();
		createBackground();
	}
	Level::~Level() {
		delete movingEntities;
		delete staticEntities;
		delete pColision;
	}
	void Level::createBackground() {
		background.addLayer("layer11.png", 0.0f, GraphicalElements::LID::empty);
		background.addLayer("layer10.png", 0.00000005f, GraphicalElements::LID::empty);
		background.addLayer("layer9.png", 0.0000001f, GraphicalElements::LID::empty);
		background.addLayer("layer8.png", 0.000003f, GraphicalElements::LID::empty);
		background.addLayer("layer7.png", 0.00006f, GraphicalElements::LID::empty);
		background.addLayer("layer6.png", 0.0007f, GraphicalElements::LID::empty);
		background.addLayer("layer5.png", 0.0008f, GraphicalElements::LID::empty);
		background.addLayer("layer4.png", 0.0009, GraphicalElements::LID::empty);
		background.addLayer("layer3.png", 0.005f, GraphicalElements::LID::empty);
		background.addLayer("layer2.png", 0.06f, GraphicalElements::LID::empty);
		background.addLayer("layer1.png", 0.08f, GraphicalElements::LID::empty);
		background.addLayer("layer0.png", 0.1f, GraphicalElements::LID::floor);
	}
	void Level::manageCollisions(float dt) {
		pColision->collide(dt);
	}
	void Level::setRandSpots() {
		spots[0] = Math::CoordF(-1740, 900);
		spots[1] = Math::CoordF(-2240, 900);
		spots[2] = Math::CoordF(-1440, 900);
		spots[3] = Math::CoordF(-600, 900);
		spots[4] = Math::CoordF(-1140, 900);
		spots[5] = Math::CoordF(3800, 900);
		spots[6] = Math::CoordF(2240, 900);
		spots[7] = Math::CoordF(4000, 900);
		spots[8] = Math::CoordF(2900, 900);
		spots[9] = Math::CoordF(2400, 900);
	}
	void Level::createPlayers(bool Player2) {
		if (Player2) {
			Entities::Characters::Player* p2 = new Entities::Characters::Player(Math::CoordF(800, 980), false, movingEntities);
			Entities::Characters::Player* p1 = new Entities::Characters::Player(Math::CoordF(900, 980), true, movingEntities, p2);
			p2->setOther(p1);
			movingEntities->setData(p2);
			movingEntities->setData(p1);
			Entities::Characters::Enemy::setPlayer1(p1);
			Entities::Characters::Enemy::setPlayer2(p2);
		}
		else {
			Entities::Characters::Player* p1 = new Entities::Characters::Player(Math::CoordF(800, 1860), true, movingEntities);
			movingEntities->setData(p1);
			Entities::Characters::Enemy::setPlayer1(p1);
		}
	}
	void Level::createThrowers() {
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
		
		Entities::Entity* ent = movingEntities->pickRandon();
		while (ent->getID() != enemy && ent->getID() != boss) {
			ent = movingEntities->pickRandon();
		}
		
		/*Entities::Entity* ent = nullptr;
		List<Entities::Entity>::iterator it = movingEntities->begin();
		int i = 0;
		while (it != movingEntities->end()) {
			if (((*it)->getID() == enemy || (*it)->getID() == boss) && i > enemiesCounter) {
				ent = (*it);
				break;
			}
			else if (((*it)->getID() == enemy || (*it)->getID() == boss))
				i++;
			++it;
		}*/
		if (ent) {
			if (ent->getID() == enemy || ent->getID() == boss) {
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
				e->setIsActive(true);
				e->setPosition(spots[randSpot]);
				enemiesCounter++;
			}
		}
	}
}