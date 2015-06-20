/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 06:07:01 by frcugy            #+#    #+#             */
/*   Updated: 2015/02/28 17:26:48 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int				check_loose_hub(t_env *env)
{
	int d;

	d = 0;
	d += fus_tab_right(env, env->len - 1, 0);
	d += move_tab_right(env, env->len - 1, 0);
	d += fus_tab_left(env, 0, 0);
	d += move_tab_left(env, 0, 0);
	d += fus_tab_up(env, 0, 0);
	d += move_tab_up(env, 0, 0);
	d += fus_tab_down(env, env->len - 1, 0);
	d += move_tab_down(env, env->len - 1, 0);
	return (d);
}

void			freetab(void **tab, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		free(tab[i]);
		i++;
	}
}

int				check_loose(t_env *env)
{
	int loose;
	int **tab;
	int **tab2;
	int i;
	int b;

	i = 0;
	tab = env->tab;
	tab2 = (int**)malloc(sizeof(int*) * env->len);
	while (i < env->len && !(b = 0))
	{
		tab2[i] = (int*)malloc(sizeof(int) * env->len);
		while (b < env->len)
		{
			tab2[i][b] = env->tab[i][b];
			b++;
		}
		i++;
	}
	env->tab = tab2;
	loose = check_loose_hub(env);
	env->tab = tab;
	freetab((void**)tab2, env->len);
	free(tab2);
	return (loose);
}

int				check_win(t_env *env)
{
	int i;
	int b;

	i = 0;
	while (i < env->len)
	{
		b = 0;
		while (b < env->len)
		{
			if (env->tab[i][b] == WIN_VALUE)
				return (1);
			b++;
		}
		i++;
	}
	return (0);
}

void			startwin(t_env *env)
{
	srand(time(0));
	initscr();
	start_color();
	init_pair(1, COLOR_BLACK, 230);
	init_pair(2, COLOR_BLACK, 180);
	init_pair(3, COLOR_BLACK, 214);
	init_pair(4, COLOR_BLACK, 208);
	init_pair(5, COLOR_BLACK, 203);
	init_pair(6, COLOR_BLACK, 196);
	init_pair(7, COLOR_BLACK, 222);
	init_pair(8, COLOR_BLACK, 221);
	init_pair(9, COLOR_BLACK, 220);
	init_pair(10, COLOR_BLACK, 228);
	init_pair(11, COLOR_BLACK, 227);
	init_pair(12, COLOR_BLACK, 226);
	noecho();
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);
	env->head = newwin(3, COLS, 0, 0);
	env->len = 4;
}
