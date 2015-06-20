/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highscore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:25:22 by tdemay            #+#    #+#             */
/*   Updated: 2015/02/28 17:26:26 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int			key_trigger_hs(int ch)
{
	if (ch == ESC)
		return (1);
	return (0);
}

void		print_hs_title(void)
{
	wborder(stdscr, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
		ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
	mvwprintw(stdscr, 4, (COLS / 2) - 22,
		" :::===  :::===== :::====  :::====  :::=====");
	mvwprintw(stdscr, 5, (COLS / 2) - 22,
		" :::     :::      :::  === :::  === :::     ");
	mvwprintw(stdscr, 6, (COLS / 2) - 22,
		"  =====  ===      ===  === =======  ======  ");
	mvwprintw(stdscr, 7, (COLS / 2) - 22,
		"     === ===      ===  === === ===  ===     ");
	mvwprintw(stdscr, 8, (COLS / 2) - 22,
		" ======   =======  ======  ===  === ========");
	mvwprintw(stdscr, 13, (COLS / 2) - 8, "10 bests scores :");
}

void		print_hs(t_env *env)
{
	int		i;
	char	*line;
	char	**split;

	i = 0;
	while (i < 10 && get_next_line(env->fp, &line) > 0)
	{
		split = ft_strsplit(line, '=');
		mvwprintw(stdscr, 15 + i, (COLS / 2) - 10, "%-10s %10s", split[0],
			split[1]);
		i++;
	}
	mvwprintw(stdscr, 27, (COLS / 2) - 12, "More scores in scores.txt");
}

void		highscore(t_env *env)
{
	int		ch;

	ch = 0;
	env->fp = open("./scores.txt", O_RDONLY);
	wclear(stdscr);
	print_hs_title();
	print_hs(env);
	while (1)
	{
		ch = getch();
		if (key_trigger_hs(ch))
			break ;
	}
	close(env->fp);
}
