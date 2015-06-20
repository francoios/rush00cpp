#ifndef SCREEN_CLASS_HPP
# define SCREEN_CLASS_HPP

# define LINE 90
# define COL 100

class Screen
{
public:
	Screen(void);
	Screen(Screen const & ref);
	~Screen(void);

	Screen const &		operator=(Screen const & ref);

	void				update(void);
	void				updateSize(void);

	int		x;
	int		y;
	bool	isWellSized;
};

#endif
