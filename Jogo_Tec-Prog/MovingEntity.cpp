#include "MovingEntity.h"

namespace Entities {
	MovingEntity::MovingEntity(Math::CoordF pos, Math::CoordF size, ID id, Math::CoordF speed) : Entity(pos, size, id), speed(speed){
		isMoving = false;
		facingLeft = false;
		canMove = true;
	}
	MovingEntity::~MovingEntity() {}
	void MovingEntity::setCanMove(bool cM) {
		canMove = cM;
	}
	bool MovingEntity::getCanMove() const {
		return canMove;
	}
	void MovingEntity::move(bool left) {
		if (canMove) {
			isMoving = true;
			if (left)
				facingLeft = true;
			else
				facingLeft = false;
		}
	}
	void MovingEntity::stop() {
		isMoving = false;
	}
	bool MovingEntity::isFacingLeft() const {
		return facingLeft;
	}
	void MovingEntity::execute(float dt) {
		position.y += GRAVIDADE * dt;
		update(dt);
	}
	void MovingEntity::moveOnCollision(Entity* ent, Math::CoordF intersection) {
		Math::CoordF otherPos = ent->getPosition();

		if (intersection.x > intersection.y) { // Colision on x direction
			if (position.x < otherPos.x)
				position.x += intersection.x;
			else
				position.x -= intersection.x;
			//speed.x = 0.0f;
		}

		else { // Colision on y direction
			if (position.y < otherPos.y)
				position.y += intersection.y;

			else
				position.y -= intersection.y;

			//speed.y = 0.0f;
		}
	}
}
