#include "Thrower.h"
#include "Projectile.h"
#include "EntitiesList.h"

namespace Entities {
	namespace Characters {
		Thrower::Thrower(Math::CoordF pos,EntitiesList* list, Player* pPlayer1, Player* pPlayer2) : Enemy(pos,Math::CoordF(THROWER_SIZE_X, THROWER_SIZE_Y),enemy, THROWER_HP, pPlayer1, pPlayer2) {
			p = new Projectile(this);
			list->setData(p);
			meleeDamage = THROWER_DAMAGE;
			if (body) {
				//body->setFillColor(sf::Color::White);
			}
			cooldown = 2.0f;
		}
		Thrower::~Thrower() {
			/*if (p) {
				list->removeData(p);
				delete p;
				p = nullptr; // Certifique-se de que `p` não será mais usado.
			}*/
		}
		void Thrower::attack() {
			
		}
		void Thrower::takeDistance(Player* p) {
			if (p->getPosition().x > position.x) {
				move(true);
			}
			else {
				move(false);
			}
		}
		void Thrower::resetCooldown() {
			cooldown = 0;
		}
		void Thrower::update(float dt) {
			stop();
			if (!p->getIsActive()) {
				cooldown += dt;
			}
			Player* near = nullptr;
			if (pPlayer1 && pPlayer2) {
				near = pPlayer2;
				if (fabs(position.x - pPlayer1->getPosition().x) < fabs(position.x - pPlayer2->getPosition().x)) { //identificar o player mais proximo
					near = pPlayer1;
				}
			}
			else if (pPlayer1) {
				near = pPlayer1;
			}
			else if (pPlayer2) {
				near = pPlayer2;
			}
			if (near) {
				//p->updateRange(near);
				float distance = position.x - near->getPosition().x;
				facingLeft = false;
				if (distance > 0) { //verificar pra qual lado atirar, mesmo que nao precise se mover
					facingLeft = true;
				}
				if (fabs(distance) > 190 && fabs(distance) < 200 && cooldown >= THROWER_COOLDOWN) { //verificar se esta dentro do range e se o cooldown esta maior q o tempo estipulado
					p->shoot(facingLeft);
				}
				else if (fabs(distance) < 191) {
					if(cooldown >= THROWER_COOLDOWN)
						p->shoot(facingLeft);
					takeDistance(near);
				}
					
				else if (fabs(distance) >= 199) //verificar se o motivo do loop foi nao ter cooldown ou estar longe
					chasePlayer(near);
				
			}
			if (isMoving) {
				if (facingLeft)
					speed.x = -THROWER_SPEED;
				else
					speed.x = THROWER_SPEED;
			}
			else {
				speed.x = 0;
			}
			
		}
		void Thrower::collide(Entity* ent, Math::CoordF intersection, float dt) {
			switch (ent->getID()) {
			case ID::obstacle:
				moveOnCollision(ent, intersection);
				break;
			case enemy:
				moveOnCollision(ent, intersection);
				break;
			case player: {
				Player* p = dynamic_cast<Player*>(ent);
				if (p) {
					p->takeDamage(meleeDamage * dt);
				}
				moveOnCollision(ent, intersection);
				break;
			}
			default:
				break;
			}
		}
	}
}
