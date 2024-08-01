#include "MovingEntity.h"

namespace Entities {
	MovingEntity::MovingEntity(Math::CoordF pos, Math::CoordF size, ID id, Math::CoordF speed) : Entity(pos, size, id), speed(speed){
		isMoving = false;
		facingLeft = false;
	}
	MovingEntity::~MovingEntity() {}
}
