#pragma once
#include "Ente.h"

namespace Entities {
	#define GRAVIDADE 120.0

	class Entity : public Ente
	{
	protected:
		Math::CoordF position;
		Math::CoordF size;
	public:
		Entity(Math::CoordF pos = Math::CoordF(0, 0), Math::CoordF size = Math::CoordF(0, 0), ID id = ID::empty);
		virtual ~Entity();
		void setPosition(Math::CoordF pos);
		Math::CoordF getPosition() const;
		Math::CoordF getSize() const;
		virtual void execute(float dt) = 0;
		virtual void render() = 0;
		virtual void update(float dt) = 0;
		virtual void collide(Entity* ent, Math::CoordF intersection) = 0;
	};
}

