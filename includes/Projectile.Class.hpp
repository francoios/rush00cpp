#ifndef PROJECTILE_CLASS_HPP
# define PROJECTILE_CLASS_HPP
# include "Entity.Class.hpp"
class Projectile : public Entity {
public:
	Projectile();
	Projectile(float x, float y, float speed, int direction);
	Projectile(Projectile const & rhs);
	~Projectile();

	Projectile const & operator=(Projectile const & rhs);
private:

protected:
};
#endif
