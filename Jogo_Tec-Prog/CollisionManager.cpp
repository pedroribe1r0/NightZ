#include "CollisionManager.h"

namespace Managers {
    CollisionManager::CollisionManager(EntitiesList* movingEntities, EntitiesList* staticEntities) : movingEntities(movingEntities), staticEntities(staticEntities){}

    CollisionManager::~CollisionManager() {
        movingEntities = nullptr;
        staticEntities = nullptr;
    }

    void CollisionManager::collide() {

    }

    void CollisionManager::clear() {

    }
}
