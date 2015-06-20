/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameCore.Class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <qmuntada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:37:32 by qmuntada          #+#    #+#             */
/*   Updated: 2015/06/20 19:24:18 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameCore.Class.hpp"

GameCore::GameCore(void)
{
	ftime = FTime();
	return ;
}

GameCore::GameCore(GameCore const & rhs)
{
	ftime = FTime();
	(void)rhs;
	return ;
}

GameCore::~GameCore(void)
{
	return ;
}

GameCore const & GameCore::operator=(GameCore const & rhs)
{
	this->ftime = rhs.ftime;
	return (*this);
}
