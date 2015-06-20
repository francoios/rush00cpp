#include "Entity.Class.hpp"

Entity::Entity(): _posX(0), _posY(0), _speed(0), _direction(0){
	std::cout << "Entity Created" << std::endl;
}

Entity::Entity(Entity const & rhs): _posX(rhs.getPosX()), _posY(rhs.getPosY()), _speed(rhs.getSpeed()), _direction(rhs.getDirection()){
	std::cout << "Entity Created" << std::endl;
}

Entity::~Entity() {
	std::cout << "Entity Destructed" << std::endl;
}

Entity const &		Entity::operator=(Entity const & rhs) {
	this->_posX = rhs.getPosX();
	this->_posY = rhs.getPosY();
	this->_speed = rhs.getSpeed();
	this->_direction = rhs.getDirection();
	return *this;
}

float		Entity::getPosX(void) const {
	return this->_posX;
}

float		Entity::getPosY(void) const {
	return this->_posY;
}

float		Entity::getSpeed(void) const {
	return this->_speed;
}

int			Entity::getDirection(void) const {
	return this->_direction;
}

void		Entity::setPosX(float x) {
	this->_posX = x;
}

void		Entity::setPosY(float y) {
	this->_posY = y;
}

void		Entity::setSpeed(float speed) {
	this->_speed = speed;
}

void		Entity::setDirection(int direction) {
	this->_direction = direction;
}
