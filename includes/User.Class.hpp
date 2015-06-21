#ifndef USER_CLASS_HPP
# define USER_CLASS_HPP
class User {
public:

	User();
	User(std::string name);
	User(User const & rhs);
	~User();

	User const &	operator=(User const & rhs);
	int				getIndex(void) const;
	int				getScore(void) const;
	std::string		getName(void) const;
	void			setScore(int score);
	void			setName(std::string name);


private:
	static int		_indexS;

protected:
	int				_index;
	int				_score;
	std::string		_name;
};
#endif
