#include "MovingEntity.h"

namespace Entities {
	MovingEntity::MovingEntity(Math::CoordF pos, Math::CoordF size, std::string text, ID id, Math::CoordF speed) : Entity(pos, size, text, id), speed(speed){
		isMoving = false;
		facingLeft = false;
	}
	MovingEntity::~MovingEntity() {}
}
