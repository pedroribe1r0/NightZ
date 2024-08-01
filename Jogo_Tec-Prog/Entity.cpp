#include "Entity.h"

namespace Entities {
	Entity::Entity(Math::CoordF pos, Math::CoordF size , ID id) : position(pos), size(size), id(id){
		body.setSize(size);
		body.update(position);
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
