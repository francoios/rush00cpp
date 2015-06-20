#ifndef SHIP_CLASS_HPP
# define SHIP_CLASS_HPP
# include "Entity.Class.hpp"
class Ship : public Entity {
public:
	Ship();
	Ship(Ship const & rhs);
	~Ship();

	Ship const & operator=(Ship const & rhs);

	int			getLife(void) const;
	int			getColor(void) const;
	int			getDamage(void) const;
	int			getFireRate(void) const;
	void		setLife(int life);
	void		setColor(int color);
	void		setDamage(int damage);
	void		setFireRate(int firerate);

private:

protected:
	int			_life;
	int			_color;
	int			_damage;
	int			_fireRate;
};

#endif
