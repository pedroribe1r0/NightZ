#include "TimeLevel.h"

namespace States {
	namespace Levels {
		TimeLevel::TimeLevel() {
			throwers = new EntitiesList();
			createLevel();
			createPlayers(false);
			createMud();
		}
		TimeLevel::~TimeLevel() {
			delete throwers;
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
		}
		void TimeLevel::execute(float dt) {
			movingEntities->execute(dt);
			staticEntities->execute(dt);
		}
		void TimeLevel::createThrowers() {
			int cont = 0;
			for (int i = 0; i < 30; i++) {
				if ((rand() % 10)) {
					Entities::Characters::Thrower* t = new Entities::Characters::Thrower(Math::CoordF(-99999, -9999), movingEntities);
					t->setIsActive(false);
					movingEntities->setData(t);
					throwers->setData(t);
					cont++;
					enemiesNumber++;
				}
				if (cont < 10 && i == 29)
					i--;
			}
		}
		void TimeLevel::spawnEnemies() {
			List<Entities::Entity>::iterator it;
			Entities::Entity* ent = nullptr;
			if (rand() % 2) {
				it = zombies->begin();
				Entities::Entity* ent = *it;
				while (it != zombies->end() && (*it)->getIsActive()) {
					++it;
				}
			}
			else {
				it = throwers->begin();
				Entities::Entity* ent = *it;
				while (it != zombies->end() && (*it)->getIsActive()) {
					++it;
				}
			}
			if (*it && !(*it)->getIsActive()) {
				ent = *it;
			}
			if (ent) {
				if (ent->getID() == enemy) {
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
					}
				}
			}
		}
	}
}
