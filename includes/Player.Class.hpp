#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP
# include "Ship.Class.hpp"
class Player: public Ship{
public:
	Player();
	Player(float x, float y, float speed, int direction, int life, int damage, int fireRate, int type);
	Player(Player const & rhs);
	~Player();

	Player const &		operator=(Player const & rhs);
	int			getType(void) const ;
	void		setType(int type);
	void		attack(void);

private:

protected:
	int			_type;
};
#endif
