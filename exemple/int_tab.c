/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:19:39 by frcugy            #+#    #+#             */
/*   Updated: 2015/02/28 05:27:43 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void			get_random_tab(int **tab, int len, int d)
{
	int i;
	int b;
	int c;

	c = 0;
	while (c < d)
	{
		i = rand() % len;
		b = rand() % len;
		if (tab[i][b] == 0)
		{
			tab[i][b] = ((rand() % 2) + 1) * 2;
			c++;
		}
	}
}

void			print_tab(int **tab, int len)
{
	int i;
	int b;

	i = 0;
	while (i < len)
	{
		b = 0;
		while (b < len)
		{
			printf("%d ", tab[i][b]);
			b++;
		}
		printf("\n");
		i++;
	}
}
