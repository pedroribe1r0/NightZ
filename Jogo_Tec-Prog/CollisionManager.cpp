#include "CollisionManager.h"

namespace Managers {
    CollisionManager::CollisionManager(EntitiesList* movingEntities, EntitiesList* staticEntities) : movingEntities(movingEntities), staticEntities(staticEntities){}

    CollisionManager::~CollisionManager() {
        movingEntities = nullptr;
        staticEntities = nullptr;
    }

    void CollisionManager::collide(float dt) {
        Entities::Entity* ent1 = nullptr;
        Entities::Entity* ent2 = nullptr;
        Math::CoordF intersect;
        Math::CoordF centerDistance;
        int i;
        List<Entities::Entity>::iterator itS = staticEntities->begin();
        while(itS != staticEntities->end()) {
            List<Entities::Entity>::iterator itM = movingEntities->begin();
            while(itM != movingEntities->end()) {
                ent1 = (*itS);
                ent2 = (*itM);

                centerDistance.x = ent2->getPosition().x - ent1->getPosition().x;
                centerDistance.y = ent2->getPosition().y - ent1->getPosition().y;

                intersect.x = fabs(centerDistance.x) - (ent1->getSize().x / 2.0f + ent2->getSize().x / 2.0f);
                intersect.y = fabs(centerDistance.y) - (ent1->getSize().y / 2.0f + ent2->getSize().y / 2.0f);

                if (intersect.x < 0.0f && intersect.y < 0.0f && ent2->getIsActive()) { // Condition to collide...
                    ent2->collide(ent1, intersect, dt);
                    //ent1->collide(ent2, intersect, dt);
                }
                ++itM;
            }
            ++itS;
        }

        /* Collide moving entities with moving entities - diagonally */
        List<Entities::Entity>::iterator itM1 = movingEntities->begin();
        i = 0;
        while (itM1 != staticEntities->end()) {
            List<Entities::Entity>::iterator itM2 = movingEntities->begin();
            for (int j = 0; j < i + 1; j++) {
                ++itM2;
            }
            while (itM2 != movingEntities->end()) {
                ent1 = (*itM1);
                ent2 = (*itM2);

                centerDistance.x = ent2->getPosition().x - ent1->getPosition().x;
                centerDistance.y = ent2->getPosition().y - ent1->getPosition().y;

                intersect.x = fabs(centerDistance.x) - (ent1->getSize().x / 2.0f + ent2->getSize().x / 2.0f);
                intersect.y = fabs(centerDistance.y) - (ent1->getSize().y / 2.0f + ent2->getSize().y / 2.0f);

                if (intersect.x < 0.0f && intersect.y < 0.0f && ent2->getIsActive() && ent1->getIsActive()) { // Condition to collide...
                    ent2->collide(ent1, intersect/2, dt);
                    ent1->collide(ent2, intersect/2, dt);
                }
                ++itM2;
            }
            i++;
            ++itM1;
        }
    }

    void CollisionManager::clear() {

    }
}
