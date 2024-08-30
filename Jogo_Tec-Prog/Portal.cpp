#include "Portal.h"

namespace Entities {
	namespace Obstacles {
		Portal::Portal(Math::CoordF pos, bool right) : Obstacle(pos, Math::CoordF(PORTAL_SIZE_X, PORTAL_SIZE_Y), false, 0), facingRight(right){
			connected = nullptr;
			setTextures();
		}
		Portal::~Portal() {
			connected = nullptr;
		}
		void Portal::update(float dt) {
			position.y -= GRAVIDADE * dt;
			sprite->update(GraphicalElements::Animation_ID::idle, facingRight, position, dt);
		}
		void Portal::execute(float dt) {
			position.y += GRAVIDADE * dt;
			update(dt);
		}
		void Portal::block(Characters::Player* ent, float dt) {
			if (connected) {
				if (connected->isFacingRight()) {
					ent->setPosition(Math::CoordF(connected->getPosition().x + 30, connected->getPosition().y));
					ent->setIsTeleporting(true);
				}
				else {
					ent->setPosition(Math::CoordF(connected->getPosition().x - 30, connected->getPosition().y));
					ent->setIsTeleporting(false);
				}
			}
		}
		void Portal::connectPortal(Portal* p) {
			if (p)
				connected = p;
		}
		bool Portal::isFacingRight() const {
			return facingRight;
		}
		void Portal::setTextures() {
			sprite = new GraphicalElements::Animation(body, Math::CoordF(3, 3));
			sprite->addNewAnimation(GraphicalElements::Animation_ID::idle, "portalfinal.png", 8);
		}
	}
}