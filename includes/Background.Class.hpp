#ifndef BACKGROUND_CLASS_HPP
# define BACKGROUND_CLASS_HPP
# include <iostream>
class Background {
public:
	Background();
	Background(Background const & rhs);
	~Background();

Background const & operator=(Background const & rhs);

void		backgroundUpdate();
char		**getTab(void) const;

private:
	char		**_tab;
	char		_field[16];
};
#endif
