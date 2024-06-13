#pragma once
#include "Entity.h"

namespace Entities {
	class MovingEntity : public Entity {
	protected:
		Math::CoordF speed;
		bool facingLeft;
		bool isMoving;
		//animacao
	public:
		MovingEntity(Math::CoordF pos = Math::CoordF(0, 0), Math::CoordF size = Math::CoordF(0, 0), std::string text = nullptr, ID id = empty, Math::CoordF speed = Math::CoordF(0,0));
		~MovingEntity();
		virtual void render() = 0;
		virtual void update(float dt) = 0;

	};
}

