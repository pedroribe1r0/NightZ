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
}
