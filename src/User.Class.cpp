#include "User.Class.hpp"

User::User(): _index(_indexS), _score(0), _name("NO NAME"){
	std::cout << "User Constructed" << std::endl;
	this->_indexS++;
}

User::User(std::string name): _index(_indexS), _score(0), _name(name) {
	std::cout << "User Constructed" << std::endl;
	this->_indexS++;
}

User::User(User const & rhs): _index(_indexS), _score(rhs.getScore()), _name(rhs.getName) {
	std::cout << "User Constructed" << std::endl;
	this->_indexS++;
}

User::~User() {
	std::cout << "User Destructed" << std::endl;
}

User const &		User::operator=(User const & rhs) {
	this->_score = rhs.getScore();
	this->_name = rhs.getName();
	return *this;
}

int				getIndex(void) const {
	return this->_index;
}

int				getScore(void) const {
	return this->_score;
}

std::string		getName(void) const {
	return this->_name;
}

void			setScore(int score) {
	this->_score = score;
	return ;
}

void			setName(std::string name) {
	this->_name = name;
}

int		User::_indexS = 0;
