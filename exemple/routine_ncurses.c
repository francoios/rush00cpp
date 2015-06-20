/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_ncurses.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:22:20 by tdemay            #+#    #+#             */
/*   Updated: 2015/02/28 17:24:47 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		key_trigger(int key_press, t_env *env, int d, int c)
{
	if (key_press == KEY_RIGHT)
	{
		d = fus_tab_right(env, env->len - 1, 0);
		c = move_tab_right(env, env->len - 1, 0);
	}
	else if (key_press == KEY_UP)
	{
		d = fus_tab_up(env, 0, 0);
		c = move_tab_up(env, 0, 0);
	}
	else if (key_press == KEY_LEFT)
	{
		d = fus_tab_left(env, 0, 0);
		c = move_tab_left(env, 0, 0);
	}
	else if (key_press == KEY_DOWN)
	{
		d = fus_tab_down(env, env->len - 1, 0);
		c = move_tab_down(env, env->len - 1, 0);
	}
	else if (key_press == ESC)
		return (-1);
	if (d > 0 || c > 0)
		get_random_tab(env->tab, env->len, 1);
	return (d);
}

void	print_center(int n, WINDOW *win, int h, int l)
{
	int		length;
	int		x;
	int		y;
	float	temp;

	length = 0;
	while (length < h)
	{
		mvwprintw(win, length, 0, "%*c", l, ' ');
		length++;
	}
	length = 0;
	temp = n;
	while (n > 0 && (length = length + 1))
		n /= 10;
	n = temp;
	temp = (l - length) / 2;
	x = 0 + (int)temp;
	y = h / 2;
	if (n != 0)
		mvwprintw(win, y, x, "%d", n);
}

void	print_grid(WINDOW **win, int **tab, int len)
{
	int		i;
	int		n;

	i = 0;
	while (i < (len * len))
	{
		n = tab[i % len][i / len];
		mvwin(win[i], ((i % len) * ((LINES - 3) / len)) + 3,
			(i / len) * (COLS / len));
		wresize(win[i], (LINES - 3) / len, COLS / len);
		wattron(win[i], COLOR_PAIR(rsqrt(n)));
		print_center(n, win[i], (LINES - 3) / len, COLS / len);
		wborder(win[i], ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
			ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
		wattroff(win[i], COLOR_PAIR(rsqrt(n)));
		wrefresh(win[i]);
		i++;
	}
}

void	print_score(t_env *env, int sc)
{
	env->score += sc;
	mvwprintw(env->head, 1, 0, "%*c", COLS, ' ');
	wborder(env->head, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
			ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
	mvwprintw(env->head, 0, (COLS / 2) - 7, "~::( 2048 )::~");
	mvwprintw(env->head, 1, 4, "score: %10d", env->score);
	wrefresh(env->head);
}

void	game(t_env *env)
{
	int		ch;
	int		sc;

	ch = 0;
	sc = 0;
	while (true)
	{
		ch = getch();
		if (check_loose(env) == 0)
			return (print_loose());
		if ((sc = key_trigger(ch, env, 0, 0)) == -1)
			return ;
		print_score(env, sc);
		print_grid(env->win, env->tab, env->len);
		if (env->victory == 0 && (env->victory = check_win(env)) == 1)
		{
			print_victory();
			usleep(3000000);
		}
		usleep(50000);
	}
}
