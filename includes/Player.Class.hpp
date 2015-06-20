/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:58:02 by qmuntada          #+#    #+#             */
/*   Updated: 2015/06/20 20:34:03 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
