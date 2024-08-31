#include "RoundLevel.h"
#include "Text.h"

namespace States {
	namespace Levels {
		RoundLevel::RoundLevel(bool player2) {
			createLevel();
			createPlayers(player2);
			createBonfires();
			createBosses();
			roundTimeCounter = 0;
			currentRound = 1;
			finalRound = 5;
			currentEnemies = 0;
			spawnTime = 8;
			deadEnemies = 0;
			currentTime = 0;
			enemiesNumber -= 35;
			nonEnemies = movingEntities->getSize() - enemiesNumber;
			std::string s = "Round : " + to_string(currentRound);
			text = new Menu::Button::Text(pGraphic->loadFont("yoster.ttf"), s, 50);
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
				if (ent->getID() == boss && currentRound >= 3 && !ent->getIsActive())
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
			pGraphic->render(text->getText());
		}
		void RoundLevel::execute(float dt) {
			movingEntities->execute(dt);
			staticEntities->execute(dt);
			currentTime += dt;
			roundTimeCounter += dt;
			
			deadEnemies = enemiesNumber - movingEntities->getSize() + nonEnemies;
			if (currentEnemies <= currentRound * (enemiesNumber/ 15) && currentTime >= spawnTime) {
				spawnEnemies();
				currentTime = 0;
				cout << "Round:  " << currentRound << endl << "  Enemies:  " << currentEnemies - deadEnemies << endl << "  Max Round:  " << currentRound * (enemiesNumber) / 15 << endl;
			}
			if ((deadEnemies >= currentRound * enemiesNumber/ 15) || (roundTimeCounter >= ROUND_MAX_TIME && currentRound < 5)) {
				enemiesNumber = enemiesNumber - deadEnemies;
				currentRound++;
				deadEnemies = 0;
				currentEnemies = 0;
				roundTimeCounter = 0;
				spawnTime--;
			}
			if ((!pPlayer1 && !pPlayer2) || currentRound > 5) {
				//empilhar o menu final
				pMachine->popState(2);
			}
			std::string s = "Round : " + to_string(currentRound);
			text->setString(s);
			if (pPlayer1) {
				text->setPos(sf::Vector2f(pPlayer1->getPosition().x - 800, 50));
			}
			else if (pPlayer2) {
				text->setPos(sf::Vector2f(pPlayer2->getPosition().x - 420, 200));
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
