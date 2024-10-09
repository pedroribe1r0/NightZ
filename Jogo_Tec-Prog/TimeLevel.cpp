#include "TimeLevel.h"
#include "Text.h"
#include "LevelCompleteMenu.h"

namespace States {
	namespace Levels {
		TimeLevel::TimeLevel(bool player2, bool load) : Level(player2 ? timemultiplayer_id : timesingleplayer_id, load)
		{
			createLevel();
			if (!load) {
				createPlayers(player2);
				createThrowers();
				currentTime = 0;
			}
			else
				loadLevel();
			createMud();
			finalTime = 120.0f;
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
		void TimeLevel::loadLevel() {
			vector<string> lines = file.lerArquivo("./levelSave.txt");
			currentTime = stoi(lines[1]);
			for (int i = 2; i < lines.size(); i++) {
				int id;
				stringstream ss(lines[i]);
				ss >> id;
				if (id == static_cast<int>(player)) {
					float posx, posy, hp;
					int points;
					bool isPlayer1;
					ss >> posx >> posy >> hp >> points >> isPlayer1;
					Entities::Characters::Player* p = new Entities::Characters::Player(Math::CoordF(posx, posy), isPlayer1, movingEntities);
					movingEntities->setData(p);
					p->setHp(hp);
					p->setPoints(points);
					if (isPlayer1) {
						Ente::setP1(p);
					}
					else
						Ente::setP2(p);
				}
				else if (id == static_cast<int>(enemy)) {
					float posx, posy, hp;
					ss >> posx >> posy >> hp;
					Entities::Characters::Zombie* z = new Entities::Characters::Zombie(Math::CoordF(posx, posy));
					z->setHp(hp);
					movingEntities->setData(z);
					enemiesNumber++;
				}
				else if (id == static_cast<int>(thrower)) {
					float posx, posy, hp;
					ss >> posx >> posy >> hp;
					Entities::Characters::Thrower* z = new Entities::Characters::Thrower(Math::CoordF(posx, posy), movingEntities);
					z->setHp(hp);
					movingEntities->setData(z);
					enemiesNumber++;
				}
				else if (id == static_cast<int>(boss)) {
					float posx, posy, hp;
					ss >> posx >> posy >> hp;
					Entities::Characters::Boss* z = new Entities::Characters::Boss(Math::CoordF(posx, posy));
					z->setHp(hp);
					movingEntities->setData(z);
					enemiesNumber++;
				}
			}
		}
		void TimeLevel::saveLevel() {
			file.removeFile("./levelSave.txt");
			vector<string> lines;
			string s = "";
			s += to_string(static_cast<int>(id)) + ' ';
			lines.push_back(s);
			s = "";
			s += to_string(currentTime) + ' ';
			lines.push_back(s);
			List<Entities::Entity>::iterator it = staticEntities->begin();
			while (it != staticEntities->end()) {
				lines.push_back((*it)->save());
				++it;
			}
			it = movingEntities->begin();
			while (it != movingEntities->end()) {
				lines.push_back((*it)->save());
				++it;
			}
			file.saveContent("./levelSave.txt", lines);
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
				Menu::LevelCompleteMenu* c = new Menu::LevelCompleteMenu();
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
			Entities::Entity* ent = nullptr;
			do {
				ent = movingEntities->pickRandon();
			} while (ent->getID() != enemy && ent->getID() != thrower && !(ent->getIsActive()));
			if (ent && ent->getPosition().x < -5000) {
				if (ent->getID() == enemy || ent->getID() == thrower) {
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
