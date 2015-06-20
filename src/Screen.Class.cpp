#include "Screen.Class.hpp"
#include <ncurses.h>


Screen::Screen(void)
{
	initscr();
	start_color();
	noecho();
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);

	isWellSized = true;


	//COLOR
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	getmaxyx(stdscr, x, y);
}

Screen::Screen(Screen const & rhs)
{
	(void)rhs;
	return ;
}

Screen::~Screen(void)
{
	return ;
}

Screen const &		Screen::operator=(Screen const & ref)
{
	(void)ref;
	return (*this);
}

void	Screen::update(void)
{
	wrefresh(stdscr);
	wclear(stdscr);
}

void	Screen::updateSize()
{
	endwin();
	refresh();
	clear();
	getmaxyx(stdscr, x, y);
	printw("%d %d\n", x, y);
	printf("%d %d\n", x, y);
}
