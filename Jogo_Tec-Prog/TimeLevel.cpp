#include "TimeLevel.h"
#include "Text.h"
#include "GameOverMenu.h"

namespace States {
	namespace Levels {
		TimeLevel::TimeLevel(bool player2) {
			createLevel();
			createPlayers(player2);
			createMud();
			createThrowers();
			finalTime = 120;
			currentTime = 0;
			std::string s = "Time Remaining : " + to_string((int)(finalTime - currentTime));
			text = new Menu::Button::Text(pGraphic->loadFont("yoster.ttf"), s, 50);
		}
		TimeLevel::~TimeLevel() {
		}
		void TimeLevel::createMud() {
			if (rand() % 2) {
				Entities::Obstacles::SlowPlatform* s = new Entities::Obstacles::SlowPlatform(Math::CoordF(-1850, 1010));
				staticEntities->setData(s);
			}
			Entities::Obstacles::SlowPlatform* s2 = new Entities::Obstacles::SlowPlatform(Math::CoordF(3447.5, 1010));
			staticEntities->setData(s2);
			if (rand() % 2) {
				Entities::Obstacles::SlowPlatform* s3 = new Entities::Obstacles::SlowPlatform(Math::CoordF(-2192, 1010));
				staticEntities->setData(s3);
			}

		}
		void TimeLevel::render() {
			background.run();
			movingEntities->render();
			staticEntities->render();
			background.renderFloor();
			pGraphic->render(text->getText());
		}
		void TimeLevel::execute(float dt) {
			movingEntities->execute(dt);
			staticEntities->execute(dt);
			currentTime += dt;
			spawnTime += dt;
			if (spawnTime >= SPAWN_TIME) {
				spawnTime = 0;
				spawnEnemies();
			}
			if (currentTime >= finalTime) {
				//empilhar estado
			}
			if ((!pPlayer1 && !pPlayer2)) {
				//empilhar o menu final
				Menu::GameOverMenu* g = new Menu::GameOverMenu();
			}
			std::string s = "Time Remaining : " + to_string((int)(finalTime - currentTime));
			text->setString(s);
			if (pPlayer1) {
				text->setPos(sf::Vector2f(pPlayer1->getPosition().x - 800, 50));
			}
			else if (pPlayer2) {
				text->setPos(sf::Vector2f(pPlayer2->getPosition().x - 700, 200));
			}
		}
		void TimeLevel::createThrowers() {
			int cont = 0;
			for (int i = 0; i < 50; i++) {
				if ((rand() % 10)) {
					Entities::Characters::Thrower* t = new Entities::Characters::Thrower(Math::CoordF(-99999, -9999), movingEntities);
					t->setIsActive(false);
					movingEntities->setData(t);
					cont++;
					enemiesNumber++;
				}
				if (cont < 10 && i == 29)
					i--;
			}
		}
		void TimeLevel::spawnEnemies() {
			Entities::Entity* ent = movingEntities->pickRandon();
			while (ent->getID() != enemy && !(ent->getIsActive())) {
				ent = movingEntities->pickRandon();
			}
			if (ent) {
				if (ent->getID() == enemy) {
					Entities::Characters::Enemy* e = dynamic_cast<Entities::Characters::Enemy*>(ent);
					int randSpot = 0;
					if (pPlayer1) {
						if (pPlayer1->getPosition().x < -80) {
							randSpot = rand() % 5;
						}
						else if (pPlayer1->getPosition().x > 1360) {
							randSpot = rand() % 5 + 5;
						}
						else {
							randSpot = -1;
						}
					}
					if (randSpot >= 0) {
						e->setIsActive(true);
						e->setPosition(spots[randSpot]);
					}
				}
			}
		}
	}
}
