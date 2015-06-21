#include "Player.Class.hpp"

Player::Player(): Ship() , _type(0), _axeH(0), _fire(false){
	std::cout<< "Player Constructed" << std::endl;
}

Player::Player(float x, float y, float speed, int direction, int life, int damage, int fireRate, int type): Ship(), _type(type) , _axeH(0), _fire(false){
	this->_posX = x;
	this->_posY = y;
	this->_speed = speed;
	this->_direction = direction;
	this->_life = life;
	this->_color = 0;
	this->_damage = damage;
	this->_fireRate = fireRate;
	if (type == 0)
		this->_color = COLOR_BLUE;
	else if (type == 1)
		this->_color = COLOR_MAGENTA;
	std::cout << "Player Constructed" << std::endl;
}

Player::Player(Player const & rhs): Ship(rhs) {
	this->_posX = rhs.getPosX();
	this->_posY = rhs.getPosY();
	this->_speed = rhs.getSpeed();
	this->_direction = rhs.getDirection();
	this->_life = rhs.getLife();
	this->_color = rhs.getColor();
	this->_damage = rhs.getDamage();
	this->_fireRate = rhs.getFireRate();
	this->_type = rhs.getType();
	this->_axeH = rhs.getAxeH();
	this->_fire = rhs.getFire();
	std::cout << "Player Constructed" << std::endl;
}

Player::~Player() {
	std::cout << "Player Destructed" << std::endl;
}

Player const &		Player::operator=(Player const & rhs) {
	this->_posX = rhs.getPosX();
	this->_posY = rhs.getPosY();
	this->_speed = rhs.getSpeed();
	this->_direction = rhs.getDirection();
	this->_life = rhs.getLife();
	this->_color = rhs.getColor();
	this->_damage = rhs.getDamage();
	this->_fireRate = rhs.getFireRate();
	this->_type = rhs.getType();
	return *this;
}

int				Player::getType(void) const {
	return this->_type;
}

int				Player::getAxeH(void) const {
	return this->_axeH;
}

bool			Player::getFire(void) const {
	return this->_fire;
}

void			Player::setType(int type) {
	this->_type = type;
	return ;
}

void			Player::setAxeH(int axeH) {
	this->_axeH = axeH;
	return ;
}

void			Player::setFire(bool fire) {
	this->_fire = fire;
	return ;
}

void			Player::attack(void) {
	std::cout << "Player attack" << std::endl;
}
