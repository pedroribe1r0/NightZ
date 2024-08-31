#include "Level.h"

namespace States {
	namespace Levels {
		Managers::EventsManager* Level::pEvent = Managers::EventsManager::getInstance();

		Level::Level() : State(ID::level) {
			srand(time(NULL));
			movingEntities = new EntitiesList();
			staticEntities = new EntitiesList();
			pColision = new Managers::CollisionManager(movingEntities, staticEntities);
			spawnTime = 0;
			enemiesNumber = 0;
			setRandSpots();
			createZombies();
			createBackground();
			createJumpers();
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
			background.addLayer("layer4.png", 0.0009f, GraphicalElements::LID::empty);
			background.addLayer("layer3.png", 0.005f, GraphicalElements::LID::empty);
			background.addLayer("layer2.png", 0.1f, GraphicalElements::LID::empty);
			background.addLayer("layer1.png", 0.08f, GraphicalElements::LID::empty);
			background.addLayer("layer0.png", 0.1f, GraphicalElements::LID::floor);
		}
		void Level::manageCollisions(float dt) {
			pColision->collide(dt);
		}
		void Level::setRandSpots() {
			spots[0] = Math::CoordF(-1740, 900);
			spots[1] = Math::CoordF(-2240, 540);
			spots[2] = Math::CoordF(-2460, 540);
			spots[3] = Math::CoordF(-600, 900);
			spots[4] = Math::CoordF(-1140, 900);
			spots[5] = Math::CoordF(3800, 540);
			spots[6] = Math::CoordF(2240, 900);
			spots[7] = Math::CoordF(3800, 540);
			spots[8] = Math::CoordF(2900, 900);
			spots[9] = Math::CoordF(2400, 900);
		}
		void Level::createPlayers(bool Player2) {
			if (Player2) {
				Entities::Characters::Player* p2 = new Entities::Characters::Player(Math::CoordF(800, 960), false, movingEntities);
				Entities::Characters::Player* p1 = new Entities::Characters::Player(Math::CoordF(900, 960), true, movingEntities, p2);
				p2->setOther(p1);
				movingEntities->setData(p2);
				movingEntities->setData(p1);
				Ente::setPlayers(p1, p2);
			}
			else {
				Entities::Characters::Player* p1 = new Entities::Characters::Player(Math::CoordF(800, 960), true, movingEntities);
				//this->p1 = p1;
				movingEntities->setData(p1);
				Ente::setPlayers(p1);
			}
		}
		void Level::createZombies() {
			int cont = 0;
			for (int i = 0; i < 50; i++) {
				if ((rand() % 10)) {
					Entities::Characters::Zombie* t = new Entities::Characters::Zombie(Math::CoordF(-99999, -9999));
					t->setIsActive(false);
					movingEntities->setData(t);
					cont++;
					enemiesNumber++;
				}
				if (cont < 10 && i == 29)
					i--;
			}
		}
		
		void Level::createLevel() {
			//-------------------------------------- Chao ------------------------------------//
			Entities::Obstacles::Simple* floor = new Entities::Obstacles::Simple(Math::CoordF(960, 1030), Math::CoordF(7120, 10));
			staticEntities->setData(floor);
			//------------------------------------ Arvores -----------------------------------//
			Entities::Obstacles::Simple* t1 = new Entities::Obstacles::Simple(Math::CoordF(0, 540), Math::CoordF(250, 1080), "tree2.png", Math::CoordF(1, 1));
			Entities::Obstacles::Simple* t2 = new Entities::Obstacles::Simple(Math::CoordF(1920, 540), Math::CoordF(250, 1080), "tree2.png", Math::CoordF(1, 1));
			Entities::Obstacles::Simple* t3 = new Entities::Obstacles::Simple(Math::CoordF(4520, 540), Math::CoordF(250, 1080), "tree2.png", Math::CoordF(1, 1));
			Entities::Obstacles::Simple* t4 = new Entities::Obstacles::Simple(Math::CoordF(-2600, 540), Math::CoordF(250, 1080), "tree2.png", Math::CoordF(1, 1));
			staticEntities->setData(t1);
			staticEntities->setData(t2);
			staticEntities->setData(t3);
			staticEntities->setData(t4);
			//---------------------------------------- Portals ------------------------------------//
			createPortals();
			//---------------------------------- Galhos ---------------------------------------//
			Entities::Obstacles::Simple* g1 = new Entities::Obstacles::Simple(Math::CoordF(480, 864), Math::CoordF(760, 50), "bushplatform.png", Math::CoordF(1, 1));
			Entities::Obstacles::Simple* g2 = new Entities::Obstacles::Simple(Math::CoordF(1460, 648), Math::CoordF(760, 50), "bushplatform.png", Math::CoordF(1, 1));
			Entities::Obstacles::Simple* g3 = new Entities::Obstacles::Simple(Math::CoordF(480, 432), Math::CoordF(760, 50), "bushplatform.png", Math::CoordF(1, 1));
			Entities::Obstacles::Simple* g4 = new Entities::Obstacles::Simple(Math::CoordF(1460, 216), Math::CoordF(760, 50), "bushplatform.png", Math::CoordF(1, 1));
			Entities::Obstacles::Simple* g5 = new Entities::Obstacles::Simple(Math::CoordF(-2120, 648), Math::CoordF(760, 50), "bushplatform.png", Math::CoordF(1, 1));
			Entities::Obstacles::Simple* g6 = new Entities::Obstacles::Simple(Math::CoordF(4040, 648), Math::CoordF(760, 50), "bushplatform.png", Math::CoordF(1, 1));
			staticEntities->setData(g1);
			staticEntities->setData(g2);
			staticEntities->setData(g3);
			staticEntities->setData(g4);
			staticEntities->setData(g5);
			staticEntities->setData(g6);
		}
		void Level::createJumpers() {
			Entities::Obstacles::Jumper* j1 = new Entities::Obstacles::Jumper(Math::CoordF(960, 990));
			staticEntities->setData(j1);
			Entities::Obstacles::Jumper* j2 = new Entities::Obstacles::Jumper(Math::CoordF(1120, 648 - JUMPER_SIZE_Y));
			staticEntities->setData(j2);
			Entities::Obstacles::Jumper* j3 = new Entities::Obstacles::Jumper(Math::CoordF(830, 864 - JUMPER_SIZE_Y));
			staticEntities->setData(j3);
			Entities::Obstacles::Jumper* j4 = new Entities::Obstacles::Jumper(Math::CoordF(830, 432 - JUMPER_SIZE_Y));
			staticEntities->setData(j4);
			Entities::Obstacles::Jumper* j5 = new Entities::Obstacles::Jumper(Math::CoordF(-1678, 990));
			staticEntities->setData(j5);
			Entities::Obstacles::Jumper* j9 = new Entities::Obstacles::Jumper(Math::CoordF(-2023, 990));
			staticEntities->setData(j9);
			Entities::Obstacles::Jumper* j6 = new Entities::Obstacles::Jumper(Math::CoordF(3620, 990));
			staticEntities->setData(j6);
			Entities::Obstacles::Jumper* j10 = new Entities::Obstacles::Jumper(Math::CoordF(3275, 990));
			staticEntities->setData(j10);
			if (rand() % 2) {
				Entities::Obstacles::Jumper* j7 = new Entities::Obstacles::Jumper(Math::CoordF(-1200, 990));
				staticEntities->setData(j7);
			}
			if (rand() % 2) {
				Entities::Obstacles::Jumper* j8 = new Entities::Obstacles::Jumper(Math::CoordF(3000, 990));
				staticEntities->setData(j8);
			}
		}
		void Level::createPortals() {
			Entities::Obstacles::Portal* P1 = new Entities::Obstacles::Portal(Math::CoordF(125, 365), true);
			Entities::Obstacles::Portal* P2 = new Entities::Obstacles::Portal(Math::CoordF(-125, 970), false);
			Entities::Obstacles::Portal* P3 = new Entities::Obstacles::Portal(Math::CoordF(1795, 153), false);
			Entities::Obstacles::Portal* P4 = new Entities::Obstacles::Portal(Math::CoordF(2045, 970), true);
			P1->connectPortal(P2);
			P3->connectPortal(P4);
			staticEntities->setData(P1);
			staticEntities->setData(P2);
			staticEntities->setData(P3);
			staticEntities->setData(P4);
			Entities::Obstacles::Portal* P5 = new Entities::Obstacles::Portal(Math::CoordF(-2475, 590), true);
			staticEntities->setData(P5);
			Entities::Obstacles::Portal* P6 = new Entities::Obstacles::Portal(Math::CoordF(4395, 590), false);
			staticEntities->setData(P6);
			P5->connectPortal(P6);
			P6->connectPortal(P5);
			if (rand() % 2) {
				Entities::Obstacles::Portal* P7 = new Entities::Obstacles::Portal(Math::CoordF(-2475, 970), true);
				P7->connectPortal(P2);
				P2->connectPortal(P7);
				staticEntities->setData(P7);
			}
			if (rand() % 2) {
				Entities::Obstacles::Portal* P8 = new Entities::Obstacles::Portal(Math::CoordF(4395, 970), false);
				P8->connectPortal(P4);
				P4->connectPortal(P8);
				staticEntities->setData(P8);
			}
		}
	}
}