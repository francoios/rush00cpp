/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FTime.Class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:53 by frcugy            #+#    #+#             */
/*   Updated: 2015/06/20 18:52:53 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTIME_HPP
# define FTIME_HPP

#include <ctime>

class FTime
{
public:
	FTime(void);
	FTime(FTime const & ref);
	~FTime(void);

	FTime const &	operator=(FTime const & ref);

	void			FTimeUpdate(void);

	float ctime;
	float deltaTime;

private:
	float _oldtime;
};

# endif
