#include "GameCore.Class.hpp"

GameCore::GameCore(void)
{
	// ftime = FTime();
	// screen = Screen();
	// decor = Background();
	return ;
}

GameCore::GameCore(GameCore const & rhs)
{
	// ftime = FTime();
	// screen = Screen();
	// decor = Background();
	(void)rhs;
	return ;
}

GameCore::~GameCore(void)
{
	return ;
}

GameCore const & GameCore::operator=(GameCore const & rhs)
{
	this->ftime = rhs.ftime;
	this->screen = rhs.screen;
	this->decor = rhs.decor;
	return (*this);
}

void			GameCore::update(void)
{
	screen.update();
	ftime.update();
	decor.update();
}
