#pragma once
#include "Body.h"

namespace Entities {
	enum ID {
		empty = 0,
		player,
		platform,
		projectile
	};

	class Entity
	{
	protected:
		Math::CoordF position;
		Math::CoordF size;
		ID id;
		Body body;
	public:
		Entity(Math::CoordF pos = Math::CoordF(0, 0), Math::CoordF size = Math::CoordF(0, 0), ID id = empty);
		~Entity();
		void setPosition(Math::CoordF pos);
		Math::CoordF getPosition() const;
		Math::CoordF getSize() const;
		ID getID() const;
		virtual void render() = 0;
		virtual void update(float dt) = 0;
	};
}

