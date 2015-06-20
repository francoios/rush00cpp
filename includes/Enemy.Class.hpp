/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.Class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:58:20 by qmuntada          #+#    #+#             */
/*   Updated: 2015/06/20 19:16:20 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
