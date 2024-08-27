#include "SingleFrameAnimation.h"
#include "GraphicManager.h"

namespace GraphicalElements {

    SingleFrameAnimation::SingleFrameAnimation(const char* path, Math::CoordF position, Math::CoordF size, float scale) :
        texture(NULL),
        body(sf::Vector2f(size.x, size.y)) {
        //texture = Managers::GraphicManager::getInstance()->loadTexture(path);
        texture = pGraphic->getInstance()->loadTexture(path);

        body.setPosition(sf::Vector2f(position.x, position.y));
        body.setScale(sf::Vector2f(scale, scale));

        body.setTexture(texture);
    }

    SingleFrameAnimation::~SingleFrameAnimation() { }
/*
    void SingleFrameAnimation::initialize(const char* path, Math::CoordF position, Math::CoordF size, float scale) {
        texture = pGraphic->loadTexture(path);

        body.setSize(sf::Vector2f(size.x, size.y));
        body.setPosition(sf::Vector2f(position.x, position.y));
        body.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
        body.setTexture(texture);
        body.setScale(sf::Vector2f(scale, scale));
    }
*/
    void SingleFrameAnimation::update(Math::CoordF position) {
        body.setPosition(sf::Vector2f(position.x, position.y));
    }
    
    void SingleFrameAnimation::render() {
        pGraphic->getInstance()->render(&body);
    }
}