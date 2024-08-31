#include "RoundLevel.h"

namespace States {
	namespace Levels {
		RoundLevel::RoundLevel() {
			bosses = new EntitiesList();
			createLevel();
			createPlayers(false);
			createBonfires();
			createBosses();
			currentRound = 1;
			finalRound = 5;
			currentEnemies = 0;
			spawnTime = 8;
			deadEnemies = 0;
			currentTime = 0;
			nonEnemies = movingEntities->getSize() - enemiesNumber;
		}
		RoundLevel::~RoundLevel() {
			delete bosses;
		}

		void RoundLevel::createBonfires() {
			Entities::Obstacles::Bonfire* b = new Entities::Obstacles::Bonfire(Math::CoordF(1150, 985));
			staticEntities->setData(b);
			if (rand() % 2) {
				Entities::Obstacles::Bonfire* b2 = new Entities::Obstacles::Bonfire(Math::CoordF(2900, 985));
				staticEntities->setData(b2);
			}
			if (rand() % 2) {
				Entities::Obstacles::Bonfire* b3 = new Entities::Obstacles::Bonfire(Math::CoordF(-1200, 985));
				staticEntities->setData(b3);
			}
		}
		void RoundLevel::spawnEnemies() {
			List<Entities::Entity>::iterator it;
			Entities::Entity* ent = nullptr;
			if (currentRound > 2 && rand() % 2) {
				it = bosses->begin();
				ent = *it;
				while (it != zombies->end() && (*it)->getIsActive()) {
					++it;
				}
			}
			else  {
				it = zombies->begin();
				ent = *it;
				while (it != zombies->end() && (*it)->getIsActive()) {
					++it;
				}
			}
			if (*it && !(*it)->getIsActive()) {
				ent = *it;
			}
			if (ent) {
				if (ent->getID() == enemy || ent->getID() == boss) {
					Entities::Characters::Enemy* e = dynamic_cast<Entities::Characters::Enemy*>(ent);
					Entities::Characters::Player* p1 = e->getPlayer1();
					Entities::Characters::Player* p2 = e->getPlayer2();
					int randSpot = 0;
					if (p1) {
						if (p1->getPosition().x < -80) {
							randSpot = rand() % 5;
						}
						else if (p1->getPosition().x > 1360) {
							randSpot = rand() % 5 + 5;
						}
						else {
							randSpot = -1;
						}
					}
					if (randSpot >= 0) {
						e->setPosition(spots[randSpot]);
						e->setIsActive(true);
						currentEnemies++;
					}
				}
			}
		}

		void RoundLevel::render() {
			background.run();
			movingEntities->render();
			staticEntities->render();
			background.renderFloor();
		}
		void RoundLevel::execute(float dt) {
			movingEntities->execute(dt);
			staticEntities->execute(dt);
			currentTime += dt;
			
			deadEnemies = enemiesNumber - movingEntities->getSize() + nonEnemies;
			if (currentTime >= spawnTime) {
				cout << "Round:  " << currentRound << endl << "  Enemies:  " << currentEnemies - deadEnemies << endl << "  Max Round:  " << currentRound * enemiesNumber / 15 << endl;
			}
			if (currentEnemies <= currentRound * enemiesNumber / 15 && currentTime >= spawnTime) {
				spawnEnemies();
				currentTime = 0;
				
			}
			if (deadEnemies >= currentRound * enemiesNumber / 15) {
				enemiesNumber = enemiesNumber - deadEnemies;
				currentRound++;
				deadEnemies = 0;
				currentEnemies = 0;
				spawnTime--;
			}
		}
		void RoundLevel::createBosses() {
			int cont = 0;
			for (int i = 0; i < 30; i++) {
				if ((rand() % 10)) {
					Entities::Characters::Boss* t = new Entities::Characters::Boss(Math::CoordF(-99999, -9999));
					t->setIsActive(false);
					movingEntities->setData(t);
					bosses->setData(t);
					cont++;
					enemiesNumber++;
				}
				if (cont < 10 && i == 29)
					i--;
			}
		}
	}
}
