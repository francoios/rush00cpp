#ifndef FTIME_HPP
# define FTIME_HPP

#include <ctime>

class FTime
{
public:
	FTime(void);
	FTime(FTime const & ref);
	~FTime(void);

	FTime const &	operator=(FTime const & ref);

	void			FTimeUpdate(void);

	float ctime;
	float deltaTime;

private:
	float _oldtime;
};

# endif
