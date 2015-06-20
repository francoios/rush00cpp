/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:48:09 by frcugy            #+#    #+#             */
/*   Updated: 2015/02/28 08:01:12 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int				move_tab_up(t_env *env, int i, int c)
{
	int b;
	int d;

	while (i < env->len && !(b = 0))
	{
		while (b < env->len)
		{
			if (env->tab[i][b] == 0 && i < env->len && (d = i + 1))
			{
				while (d < env->len)
				{
					if (env->tab[d][b] != 0 && (c = 1))
					{
						env->tab[i][b] = env->tab[d][b];
						env->tab[d][b] = 0;
						break ;
					}
					d++;
				}
			}
			b++;
		}
		i++;
	}
	return (c);
}

int				move_tab_down(t_env *env, int i, int c)
{
	int b;
	int d;

	while (i >= 0 && (b = env->len - 1))
	{
		while (b >= 0)
		{
			if (env->tab[i][b] == 0 && i >= 0 && (d = i - 1) >= 0)
				while (d >= 0)
				{
					if (env->tab[d][b] != 0 && (c = 1))
					{
						env->tab[i][b] = env->tab[d][b];
						env->tab[d][b] = 0;
						break ;
					}
					d--;
				}
			b--;
		}
		i--;
	}
	return (c);
}

int				move_tab_right(t_env *env, int i, int c)
{
	int b;
	int d;

	while (i >= 0 && (b = env->len - 1))
	{
		while (b >= 0)
		{
			if (env->tab[i][b] == 0 && b >= 0 && (d = b - 1) >= 0)
			{
				while (d >= 0)
				{
					if (env->tab[i][d] != 0 && (c = 1))
					{
						env->tab[i][b] = env->tab[i][d];
						env->tab[i][d] = 0;
						break ;
					}
					d--;
				}
			}
			b--;
		}
		i--;
	}
	return (c);
}

int				move_tab_left(t_env *env, int i, int c)
{
	int b;
	int d;

	while (i < env->len && !(b = 0))
	{
		while (b < env->len)
		{
			if (env->tab[i][b] == 0 && i < env->len && (d = b + 1))
			{
				while (d < env->len)
				{
					if (env->tab[i][d] != 0 && (c = 1))
					{
						env->tab[i][b] = env->tab[i][d];
						env->tab[i][d] = 0;
						break ;
					}
					d++;
				}
			}
			b++;
		}
		i++;
	}
	return (c);
}
