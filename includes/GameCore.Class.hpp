/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameCore.Class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:56:43 by qmuntada          #+#    #+#             */
/*   Updated: 2015/06/20 16:35:40 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMECORE_CLASS_HPP
# define GAMECORE_CLASS_HPP

# include <iostream>

# include "FTime.Class.hpp"
# include "Screen.Class.hpp"

class GameCore
{
public:
	GameCore();
	GameCore(GameCore const &rhs);
	~GameCore();

	GameCore const &	operator=(GameCore const & rhs);
	void				Update(void);

	//Screen		screen; // Window handling
	//Ft_Time		ftime; // Time/frame handling
	// ICI TOUTES LES CLASSE PRATIQUE COMME SCREEN, TIME, QUI
	// SERONT AINSI ACCESSIBLE GRACE A L'INSTANCE DE GAMECORE

private:

protected:

};

#endif
