#pragma once
#include "Entity.h"

namespace Entities {
	class MovingEntity : public Entity {
	protected:
		Math::CoordF speed;
		bool facingLeft;
		bool isMoving;
		bool canMove;
		//animacao
	public:
		MovingEntity(Math::CoordF pos = Math::CoordF(0, 0), Math::CoordF size = Math::CoordF(0, 0), ID id = ID::empty);
		virtual ~MovingEntity();
		void setCanMove(bool cM);
		bool getCanMove() const;
		bool isFacingLeft() const;
		void move(bool left);
		void stop();
		virtual void update(float dt) = 0;
		virtual void collide(Entity* ent, Math::CoordF intersection, float dt) = 0;
	};
}

