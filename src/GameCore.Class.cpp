#include "GameCore.Class.hpp"

GameCore::GameCore(void)
{
	ftime = FTime();
	screen = Screen();
	return ;
}

GameCore::GameCore(GameCore const & rhs)
{
	ftime = FTime();
	screen = Screen();
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
	return (*this);
}

void			GameCore::update(void)
{
	screen.update();
	ftime.update();
}
