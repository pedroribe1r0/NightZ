#include "Level.h"

namespace Levels {
	Managers::EventsManager* Level::pEvent = Managers::EventsManager::getInstance();

	Level::Level() {
		movingEntities = new EntitiesList();
		staticEntities = new EntitiesList();
		pColision = new Managers::CollisionManager(movingEntities, staticEntities);
	}
	Level::~Level() {

	}
}