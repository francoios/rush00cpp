/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:48:18 by frcugy            #+#    #+#             */
/*   Updated: 2015/02/28 16:04:56 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int				fus_tab_up(t_env *e, int i, int c)
{
	int b;
	int d;

	while (i < e->len && !(b = 0))
	{
		while (b < e->len)
		{
			if (e->tab[i][b] != 0 && i < e->len && (d = i + 1))
				while (d < e->len)
				{
					if (e->tab[d][b] == e->tab[i][b] && (c += e->tab[i][b]))
					{
						e->tab[i][b] *= 2;
						e->tab[d][b] = 0;
						break ;
					}
					else if (e->tab[d][b] != 0 && e->tab[d][b] != e->tab[i][b])
						break ;
					d++;
				}
			b++;
		}
		i++;
	}
	return (c);
}

int				fus_tab_down(t_env *e, int i, int c)
{
	int b;
	int d;

	while (i >= 0 && (b = e->len - 1))
	{
		while (b >= 0)
		{
			if (e->tab[i][b] != 0 && i >= 0 && (d = i - 1) >= 0)
				while (d >= 0)
				{
					if (e->tab[d][b] == e->tab[i][b] && (c += e->tab[i][b]))
					{
						e->tab[i][b] *= 2;
						e->tab[d][b] = 0;
						break ;
					}
					else if (e->tab[d][b] != 0 && e->tab[d][b] != e->tab[i][b])
						break ;
					d--;
				}
			b--;
		}
		i--;
	}
	return (c);
}

int				fus_tab_right(t_env *e, int i, int c)
{
	int b;
	int d;

	while (i >= 0 && (b = e->len - 1))
	{
		while (b >= 0)
		{
			if (e->tab[i][b] != 0 && b >= 0 && (d = b - 1) >= 0)
				while (d >= 0)
				{
					if (e->tab[i][d] == e->tab[i][b] && (c += e->tab[i][b]))
					{
						e->tab[i][b] *= 2;
						e->tab[i][d] = 0;
						break ;
					}
					else if (e->tab[i][d] != 0 && e->tab[i][d] != e->tab[i][b])
						break ;
					d--;
				}
			b--;
		}
		i--;
	}
	return (c);
}

int				fus_tab_left(t_env *e, int i, int c)
{
	int b;
	int d;

	while (i < e->len && !(b = 0))
	{
		while (b < e->len)
		{
			if (e->tab[i][b] != 0 && i < e->len && (d = b + 1))
				while (d < e->len)
				{
					if (e->tab[i][d] == e->tab[i][b] && (c += e->tab[i][b]))
					{
						e->tab[i][b] *= 2;
						e->tab[i][d] = 0;
						break ;
					}
					else if (e->tab[i][d] != 0 && e->tab[d][b] != e->tab[i][b])
						break ;
					d++;
				}
			b++;
		}
		i++;
	}
	return (c);
}

char			*ft_str_super_dup2(char *str, char c)
{
	char	*dest;
	int		i;
	int		b;

	dest = (char*)malloc(sizeof(char) * ft_strlen(str));
	i = 0;
	b = 0;
	while (str[i] && str[i] != c)
	{
		dest[b] = str[i];
		b++;
		i++;
	}
	dest[b] = '\0';
	return (dest);
}
