#include "RoundLevel.h"

namespace States {
	namespace Levels {
		RoundLevel::RoundLevel() {
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
			Entities::Entity* ent = nullptr;
			do {
				ent = movingEntities->pickRandon();
				if (ent->getID() == boss && currentRound >= 3 && ent->getIsActive())
					break;
			} while (ent->getID() != enemy && !(ent->getIsActive()));
			if (ent) {
				if (ent->getID() == enemy || (ent->getID() == boss && currentRound >= 3)) {
					Entities::Characters::Enemy* e = dynamic_cast<Entities::Characters::Enemy*>(ent);
					Entities::Characters::Player* p1 = e->getPlayer1();
					Entities::Characters::Player* p2 = e->getPlayer2();
					int randSpot = 0;
					if (p1) {
						if (p1->getPosition().x < -80) {
							randSpot = rand() % 5;
						}
						else if (p1->getPosition().x > 1920) {
							randSpot = rand() % 5 + 5;
						}
						else {
							randSpot = -1;
						}
					}
					if (randSpot >= 0) {
						e->setIsActive(true);
						e->setPosition(spots[randSpot]);
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
			if (currentEnemies <= currentRound * ((enemiesNumber - 35)/ 15) && currentTime >= spawnTime) {
				spawnEnemies();
				currentTime = 0;
				cout << "Round:  " << currentRound << endl << "  Enemies:  " << currentEnemies - deadEnemies << endl << "  Max Round:  " << currentRound * ((enemiesNumber-40) / 15) << endl;
			}
			if (deadEnemies >= currentRound * (enemiesNumber - 35)/ 15) {
				enemiesNumber = enemiesNumber - deadEnemies;
				currentRound++;
				deadEnemies = 0;
				currentEnemies = 0;
				spawnTime--;
			}
			if (currentRound > 5) {
				//empilhar o menu final
				cout << "acabou" << endl;
			}
		}
		void RoundLevel::createBosses() {
			int cont = 0;
			for (int i = 0; i < 50; i++) {
				if ((rand() % 10)) {
					Entities::Characters::Boss* t = new Entities::Characters::Boss(Math::CoordF(-99999, -9999));
					t->setIsActive(false);
					movingEntities->setData(t);
					cont++;
					enemiesNumber++;
				}
				if (cont < 10 && i == 29)
					i--;
			}
		}
	}
}
