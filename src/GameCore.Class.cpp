#include "GameCore.Class.hpp"

GameCore::GameCore(void)
{
	ftime = FTime();
	return ;
}

GameCore::GameCore(GameCore const & rhs)
{
	ftime = FTime();
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
	return (*this);
}
