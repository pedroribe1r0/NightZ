#pragma once
#include "EventsManager.h"
namespace Levels {
	class Level : public Ente
	{
	protected:
		static Managers::EventsManager* pEvent;
		Managers::CollisionManager* pColision;
		EntitiesList* staticEntities;
		EntitiesList* movingEntities;
	public:
		Level();
		~Level();
		virtual void execute() = 0;
		//void manageCollisions();
		//void createThrowers();
		//void createThrowers();
	};
}

