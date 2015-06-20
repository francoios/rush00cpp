#ifndef SCREEN_CLASS_HPP
# define SCREEN_CLASS_HPP

# define LINE = 40
# define COL = 80

class Screen
{
public:
	Screen(void);
	Screen(Screen const & ref);
	~Screen(void);

	Screen const &		operator=(Screen const & ref);

	void				update(void);

	int		x;
	int		y;
};

#endif
