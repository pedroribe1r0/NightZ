#include "RoundLevel.h"
#include "Text.h"
#include "LevelCompleteMenu.h"

namespace States {
	namespace Levels {
		RoundLevel::RoundLevel(bool player2, bool load) : Level(player2 ? roundmultiplayer_id : roundsingleplayer_id, load)
		{
			createLevel();
			if (!load) {
				createBosses();
				createPlayers(player2);
				currentRound = 1;
			}
			else
				loadLevel();
			createBonfires();
			roundTimeCounter = 0;
			finalRound = 5;
			currentEnemies = 0;
			spawnTime = 9 - currentRound;
			deadEnemies = 0;
			currentTime = 0;
			enemiesNumber -= 35;
			nonEnemies = movingEntities->getSize() - enemiesNumber;
			std::string s = "Round : " + to_string(currentRound);
			text = new Menu::Button::Text(pGraphic->loadFont("yoster.ttf"), s, 50);
		}
		RoundLevel::~RoundLevel() {
			
		}

		void RoundLevel::loadLevel() {
			vector<string> lines = file.lerArquivo("./levelSave.txt");
			currentRound = stoi(lines[1]);
			cout << currentRound << endl;
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
			if (pPlayer1 && pPlayer2) {
				pPlayer1->setOther(pPlayer2);
				pPlayer2->setOther(pPlayer1);
			}
		}
		void RoundLevel::saveLevel() {
			file.removeFile("./levelSave.txt");
			vector<string> lines;
			string s = "";
			s += to_string(static_cast<int>(id)) + ' ';
			lines.push_back(s);
			s = "";
			s += to_string(currentRound) + ' ';
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

		void RoundLevel::createBonfires() {
			Entities::Obstacles::Bonfire* b = new Entities::Obstacles::Bonfire(Math::CoordF(1150, 985));
			staticEntities->setData(b);
			if (rand() % 2) {
				Entities::Obstacles::Bonfire* b2 = new Entities::Obstacles::Bonfire(Math::CoordF(2900, 985));
				staticEntities->setData(b2);
			}
			if (rand() % 2) {
				Entities::Obstacles::Bonfire* b3 = new Entities::Obstacles::Bonfire(Math::CoordF(-900, 985));
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
			if (ent && ent->getPosition().x < -5000) {
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
			}
			
			if ((deadEnemies >= currentRound * enemiesNumber/ 15) || (roundTimeCounter >= ROUND_MAX_TIME && currentRound < 5)) {
				enemiesNumber = enemiesNumber - deadEnemies;
				currentRound++;
				deadEnemies = 0;
				currentEnemies = 0;
				roundTimeCounter = 0;
				spawnTime--;
			}
			
			if ((!pPlayer1 && !pPlayer2)) {
				Menu::GameOverMenu* g = new Menu::GameOverMenu();
			}
			else if (currentRound > 5) {
				Menu::LevelCompleteMenu* c = new Menu::LevelCompleteMenu();
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
