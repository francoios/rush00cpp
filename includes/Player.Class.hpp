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
	int			getAxeH(void) const;
	bool		getFire(void) const;
	void		setType(int type);
	void		setFire(bool fire);
	void		setAxeH(int axeH);
	void		attack(void);

private:

protected:
	int			_type;
	int			_axeH;
	bool		_fire;
};
#endif
