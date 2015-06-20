#include "Ship.Class.hpp"

Ship::Ship():Entity() , _life(0), _color(0), _damage(0), _fireRate(0) {
	std::cout << "Ship Constructed" << std::endl;
}

Ship::Ship(Ship const & rhs):Entity(rhs) , _life(rhs.getLife()), _color(rhs.getColor()), _damage(rhs.getDamage()), _fireRate(rhs.getFireRate()){
	std::cout << "Ship Constructed" << std::endl;
}

Ship::~Ship() {
	std::cout << "Ship Destructed" << std::endl;
}

Ship const & Ship::operator=(Ship const & rhs) {
	this->_posX = rhs.getPosX();
	this->_posY = rhs.getPosY();
	this->_speed = rhs.getSpeed();
	this->_direction = rhs.getDirection();
	this->_life = rhs.getLife();
	this->_color = rhs.getColor();
	this->_damage = rhs.getDamage();
	this->_fireRate = rhs.getFireRate();
	return *this;
}

int			Ship::getLife(void) const {
	return this->_life;
}

int			Ship::getColor(void) const {
	return this->_color;
}

int			Ship::getDamage(void) const {
	return this->_damage;
}

int			Ship::getFireRate(void) const {
	return this->_fireRate;
}

void		Ship::setLife(int life) {
	this->_life = life;
	return ;
}

void		Ship::setColor(int color) {
	this->_color = color;
	return ;
}

void		Ship::setDamage(int damage) {
	this->_damage = damage;
	return ;
}

void		Ship::setFireRate(int firerate) {
	this->_fireRate = firerate;
	return ;
}
