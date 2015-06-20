#ifndef ENTITY_CLASS_HPP
# define ENTITY_CLASS_HPP
# include <ncurses.h>
# include <iostream>

class Entity {
public:
	Entity();
	Entity(Entity const & rhs);
	~Entity();

	Entity const &	operator=(Entity const & rhs);
	float		getPosX(void) const;
	float		getPosY(void) const;
	float		getSpeed(void) const;
	int			getDirection(void) const;
	void		setPosX(float x);
	void		setPosY(float y);
	void		setSpeed(float speed);
	void		setDirection(int direction);
private:

protected:
float		_posX;
float		_posY;
float		_speed;
int			_direction;
};

#endif
