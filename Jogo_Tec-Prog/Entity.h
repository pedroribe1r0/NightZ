#pragma once
#include "Ente.h"
class EntitiesList;
namespace Entities {
	#define GRAVIDADE 600.0f

	class Entity : public Ente
	{
	protected:
		Math::CoordF position;
		Math::CoordF size;
		bool isActive;
	public:
		Entity(Math::CoordF pos = Math::CoordF(0, 0), Math::CoordF size = Math::CoordF(0, 0), ID id = ID::empty);
		virtual ~Entity();
		void setPosition(Math::CoordF pos);
		Math::CoordF getPosition() const;
		Math::CoordF getSize() const;
		virtual void execute(float dt) = 0;
		virtual void render();
		virtual void update(float dt) = 0;
		virtual void collide(Entity* ent, Math::CoordF intersection, float dt) = 0;
		bool getIsActive() const;
		void setIsActive(bool ac);
	};
}

