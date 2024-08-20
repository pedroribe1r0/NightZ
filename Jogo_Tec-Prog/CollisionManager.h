#pragma once
#include "EntitiesList.h"

namespace Managers {
    class CollisionManager
    {
    private:
        EntitiesList* staticEntities;
        EntitiesList* movingEntities;
    public:
        CollisionManager(EntitiesList* movingEntities, EntitiesList* staticEntities);

        ~CollisionManager();

        void collide();

        void clear();
    };
}

