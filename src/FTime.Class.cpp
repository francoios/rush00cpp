#include "FTime.Class.hpp"

FTime::FTime(void)
{
	clock_t	timer;

	timer = clock();

	_oldtime = timer;
	ctime = _oldtime;
	deltaTime = 0.0f;
	return ;
}

FTime::FTime(FTime const & ref)
{
	_oldtime = ref._oldtime;
	ctime = ref.ctime;
	deltaTime = ref.deltaTime;
	return ;
}

FTime::~FTime(void)
{
	return ;
}

FTime const &		FTime::operator=(FTime const & ref)
{
	this->ctime = ref.ctime;
	this->deltaTime = ref.deltaTime;
	return (*this);
}

void				FTime::update(void)
{
	clock_t	timer;

	timer = clock();
	_oldtime = ctime;
	ctime = timer;
	deltaTime = ctime - _oldtime;
	return ;
}
