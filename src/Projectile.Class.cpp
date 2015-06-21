#include "Projectile.Class.hpp"

Projectile::Projectile(): Entity() {
	std::cout<< "Projectile Created" << std::endl;
}

Projectile::Projectile(float x, float y, float speed, int direction):Entity() {
	this->_posX = x;
	this->_posY = y;
	this->_speed = speed;
	this->_direction = direction;
	std::cout<< "Projectile Created" << std::endl;
}

Projectile::Projectile(Projectile const & rhs): Entity(rhs) {
	std::cout<< "Projectile Created" << std::endl;
}

Projectile::~Projectile() {
	std::cout << "Projectile Destroyed" << std::endl;
}

Projectile const & Projectile::operator=(Projectile const & rhs) {
	this->_posX = rhs.getPosX();
	this->_posY = rhs.getPosY();
	this->_speed = rhs.getSpeed();
	this->_direction = rhs.getDirection();
	return *this;
}
