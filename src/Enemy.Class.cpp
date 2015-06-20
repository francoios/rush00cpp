/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.Class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:58:22 by qmuntada          #+#    #+#             */
/*   Updated: 2015/06/20 20:42:36 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.Class.hpp"

Enemy::Enemy(): Ship(),_index(_indexS), _type(0) {
	std::cout << "Enemy Created" << std::endl;
	this->_indexS++;
}

Enemy::Enemy(float x, float y, float speed, int direction, int life, int damage, int fireRate, int type):
Ship(), _index(_indexS), _type(type) {
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
	else if (type == 2)
		this->_color = COLOR_YELLOW;
	else
		this->_color = COLOR_WHITE;
	std::cout << "Enemy Created #" << this->_index << std::endl;
	this->_indexS++;
}

Enemy::Enemy(Enemy const & rhs): Ship(rhs), _index(_indexS), _type(rhs.getType()) {
	std::cout << "Enemy Created #" << this->_index << std::endl;
	this->_indexS++;
}

Enemy::~Enemy() {
	std::cout << "Enemy Destructed #" << this->_index << std::endl;
}

Enemy const & Enemy::operator=(Enemy const & rhs) {
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

int				Enemy::getType(void) const{
	return this->_type;
}

void			Enemy::setType(int type) {
	this->_type = type;
	return ;
}

	int Enemy::_indexS = 0;
