#include "GameCore.Class.hpp"
#include <ncurses.h>
#include "Enemy.Class.hpp"

int main(void)
{
	Enemy	toto = Enemy(10, 5, 3.4, 2, 1, 1, 5, 2);
	std::cout<< ".getPosX = " << toto.getPosX() << std::endl;
	std::cout<< ".getPosY = " << toto.getPosY() << std::endl;
	std::cout<< ".getSpeed = " << toto.getSpeed() << std::endl;
	std::cout<< ".getDirection = " << toto.getDirection() << std::endl;
	std::cout<< ".getLife = " << toto.getLife() << std::endl;
	std::cout<< ".getColor = " << toto.getColor() << std::endl;
	std::cout<< ".getDamage = " << toto.getDamage() << std::endl;
	std::cout<< ".getFireRate = " << toto.getFireRate() << std::endl;
	std::cout<< ".getType = " << toto.getType() << std::endl;

	Enemy	toto2(toto);
	std::cout<< ".getPosX = " << toto2.getPosX() << std::endl;
	std::cout<< ".getPosY = " << toto2.getPosY() << std::endl;
	std::cout<< ".getSpeed = " << toto2.getSpeed() << std::endl;
	std::cout<< ".getDirection = " << toto2.getDirection() << std::endl;
	std::cout<< ".getLife = " << toto2.getLife() << std::endl;
	std::cout<< ".getColor = " << toto2.getColor() << std::endl;
	std::cout<< ".getDamage = " << toto2.getDamage() << std::endl;
	std::cout<< ".getFireRate = " << toto2.getFireRate() << std::endl;
	std::cout<< ".getType = " << toto2.getType() << std::endl;

	return (0);
}
