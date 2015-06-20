#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP
# include "Ship.Class.hpp"
class Enemy: public Ship{
public:
	Enemy();
	Enemy(float x, float y, float speed, int direction, int life, int damage, int fireRate, int type);
	Enemy(Enemy const & rhs);
	~Enemy();

	Enemy const &		operator=(Enemy const & rhs);
	int			getType(void) const;
	void		setType(int type);

private:
	static int _indexS;

protected:
	int		_index;
	int		_type;
};
#endif
