#pragma once
#include "EntitiesList.h"
//O codigo usado de base foi feito por Matheus Augusto Burda(Burda Canal no Youtube)

namespace Managers {
    class CollisionManager
    {
    private:
        EntitiesList* staticEntities;
        EntitiesList* movingEntities;
    public:
        CollisionManager(EntitiesList* movingEntities = nullptr, EntitiesList* staticEntities = nullptr);

        ~CollisionManager();

        void collide(float dt = 0);

        void clear();
    };
}

