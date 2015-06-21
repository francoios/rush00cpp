#include "Background.Class.hpp"
#include "Screen.Class.hpp"
#include <stdio.h>

Background::Background() {
std::cout << "Background created" << std::endl;

	this->_tab = new char *[LINE];
	int c = 0;
	while (c <= LINE)
	{
		this->_tab[c] = new char[COL];
		c++;
	}

	this->_field[0] = ' ';
	this->_field[1] = ' ';
	this->_field[2] = ' ';
	this->_field[3] = ' ';
	this->_field[4] = ' ';
	this->_field[5] = ' ';
	this->_field[6] = ' ';
	this->_field[7] = ' ';
	this->_field[8] = ' ';
	this->_field[9] = ' ';
	this->_field[10] = ' ';
	this->_field[11] = ' ';
	this->_field[12] = ' ';
	this->_field[13] = ' ';
	this->_field[14] = '*';
	this->_field[15] = '\0';

	int i = -1;
	while (++i < LINE)
	{
		int b = -1;
		while (++b < COL)
			this->_tab[i][b] = this->_field[rand() % 15];
		this->_tab[i][b] = '\0';
	}
}

Background::Background(Background const & rhs){
	(void)rhs;
	std::cout << "Background created" << std::endl;
}

Background::~Background() {
	std::cout << "Background Destructed" << std::endl;

}

Background const & Background::operator=(Background const & rhs) {
	(void)rhs;
	return *this;
}

char		**Background::getTab(void) const {
	return this->_tab;
}

void				Background::backgroundUpdate() {
	int i;
	int b;

	i = LINE;
	while (--i > 0)
	{
		b = -1;
		while (++b < COL)
			this->_tab[i][b] = this->_tab[i - 1][b];
	}
	b = -1;
	while (++b < COL)
		this->_tab[i][b] = this->_field[rand() % 15];
}
