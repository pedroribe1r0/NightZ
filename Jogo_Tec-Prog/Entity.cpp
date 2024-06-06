#include "Entity.h"

namespace Entities {
	Entity::Entity(Math::CoordF pos, Math::CoordF size, std::string text , ID id) : position(pos), size(size), id(id), textPath(text){
		pGraphic = Managers::GraphicManager::getInstance();
		pGraphic->loadTexture(textPath);
		
	}
	Entity::~Entity() {

	}
	void Entity::setPosition(Math::CoordF pos) {
		position = pos;
	}
	Math::CoordF Entity::getPosition() const{
		return position;
	}
	Math::CoordF Entity::getSize() const{
		return size;
	}
	ID Entity::getID() const{
		return id;
	}
}
