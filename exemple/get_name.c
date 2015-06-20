/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:18:13 by tdemay            #+#    #+#             */
/*   Updated: 2015/02/28 17:21:44 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int			key_trigger_name(int ch, t_env *env)
{
	int		size;

	size = ft_strlen(env->login);
	if (ch == 10 && (size - 1) >= 0)
		return (1);
	else if (ch == 127 && (size - 1) >= 0)
		env->login[size - 1] = '\0';
	else if (ft_isprint(ch) && size < 10)
	{
		env->login[size] = ch;
		env->login[size + 1] = '\0';
	}
	return (0);
}

void		get_name(t_env *env)
{
	int		ch;
	WINDOW	*form;

	wclear(stdscr);
	if ((form = newwin(3, 20, 23, (COLS / 2) - 10)) && env->victory)
		print_victory();
	else
		print_loose();
	wborder(stdscr, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
		ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
	mvwprintw(stdscr, 18, (COLS / 2) - 12, "with score : %10d", env->score);
	mvwprintw(stdscr, 26, (COLS / 2) - 13, "enter login and press enter");
	while (true)
	{
		ch = getch();
		wclear(form);
		mvwin(form, 23, (COLS / 2) - 10);
		wborder(form, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
			ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
		mvwprintw(form, 1, 1, "%s", env->login);
		wrefresh(form);
		if (key_trigger_name(ch, env))
			break ;
		usleep(50000);
	}
}
