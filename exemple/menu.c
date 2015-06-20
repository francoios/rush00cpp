/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 06:20:15 by tdemay            #+#    #+#             */
/*   Updated: 2015/02/28 16:15:41 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void		print_new_game(WINDOW *win, int sel)
{
	mvwin(win, 17, (COLS / 2) - 10);
	if (sel == 0)
		wattron(win, COLOR_PAIR(4));
	wborder(win, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
		ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
	mvwprintw(win, 1, 1, "     New Game     ");
	if (sel == 0)
		wattroff(win, COLOR_PAIR(4));
	wrefresh(win);
}

void		print_highscore(WINDOW *win, int sel)
{
	mvwin(win, 20, (COLS / 2) - 10);
	if (sel == 1)
		wattron(win, COLOR_PAIR(4));
	wborder(win, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
		ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
	mvwprintw(win, 1, 1, "     Highscore    ");
	if (sel == 1)
		wattroff(win, COLOR_PAIR(4));
	wrefresh(win);
}

void		print_quit_game(WINDOW *win, int sel)
{
	mvwin(win, 23, (COLS / 2) - 10);
	if (sel == 2)
		wattron(win, COLOR_PAIR(4));
	wborder(win, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
		ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
	mvwprintw(win, 1, 1, "     Quit Game    ");
	if (sel == 2)
		wattroff(win, COLOR_PAIR(4));
	wrefresh(win);
}

int			key_trigger_menu(int ch, int *sel, t_env *env)
{
	if (ch == KEY_UP)
		*sel = (*sel > 0) ? *sel - 1 : 0;
	else if (ch == KEY_DOWN)
		*sel = (*sel < 2) ? *sel + 1 : 2;
	else if (ch == KEY_LEFT)
		env->len = (env->len > 4) ? env->len - 1 : 4;
	else if (ch == KEY_RIGHT)
		env->len = (env->len < 10) ? env->len + 1 : 10;
	else if (ch == 10)
		return (1);
	else if (ch == ESC)
	{
		*sel = 2;
		return (1);
	}
	return (0);
}

int			menu(t_env *env, int ch, int sel)
{
	WINDOW	*new_game;
	WINDOW	*highscore;
	WINDOW	*quit_game;

	new_game = newwin(3, 20, 17, (COLS / 2) - 10);
	highscore = newwin(3, 20, 20, (COLS / 2) - 10);
	quit_game = newwin(3, 20, 23, (COLS / 2) - 10);
	while (true)
	{
		ch = getch();
		wclear(stdscr);
		print_title(env);
		wrefresh(stdscr);
		print_quit_game(quit_game, sel);
		print_highscore(highscore, sel);
		print_new_game(new_game, sel);
		if (key_trigger_menu(ch, &sel, env))
			break ;
		usleep(50000);
	}
	delwin(highscore);
	delwin(new_game);
	delwin(quit_game);
	return (sel);
}
