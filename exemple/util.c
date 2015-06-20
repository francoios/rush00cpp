/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 05:32:14 by tdemay            #+#    #+#             */
/*   Updated: 2015/02/28 16:51:01 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		rsqrt(int number)
{
	int		i;

	i = 0;
	while ((number = number / 2))
		i++;
	return (i);
}

int		power_two(unsigned int x)
{
	while (((x & 1) == 0) && x > 1)
		x >>= 1;
	if (x != 1)
		write(1, "game_2048 : Error wrong define WIN_VALUE.\n", 42);
	return (x == 1);
}

void	print_victory(void)
{
	mvwprintw(stdscr, 8, (COLS / 2) - 28,
		" :::  === ::: :::===== :::==== :::====  :::====  ::: ===");
	mvwprintw(stdscr, 9, (COLS / 2) - 28,
		" :::  === ::: :::      :::==== :::  === :::  === ::: ===");
	mvwprintw(stdscr, 10, (COLS / 2) - 28,
		" ===  === === ===        ===   ===  === =======   ===== ");
	mvwprintw(stdscr, 11, (COLS / 2) - 28,
		"  ======  === ===        ===   ===  === === ===    ===  ");
	mvwprintw(stdscr, 12, (COLS / 2) - 28,
		"    ==    ===  =======   ===    ======  ===  ===   ===  ");
	mvwprintw(stdscr, 13, (COLS / 2) - 28,
		"                                                        ");
	wrefresh(stdscr);
}

void	print_loose(void)
{
	mvwprintw(stdscr, 8, (COLS / 2) - 22,
		" :::      :::====  :::====  :::===  :::=====");
	mvwprintw(stdscr, 9, (COLS / 2) - 22,
		" :::      :::  === :::  === :::     :::     ");
	mvwprintw(stdscr, 10, (COLS / 2) - 22,
		" ===      ===  === ===  ===  =====  ======  ");
	mvwprintw(stdscr, 11, (COLS / 2) - 22,
		" ===      ===  === ===  ===     === ===     ");
	mvwprintw(stdscr, 12, (COLS / 2) - 22,
		" ========  ======   ======  ======  ========");
	wrefresh(stdscr);
}

void	print_title(t_env *env)
{
	wborder(stdscr, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
		ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
	mvwprintw(stdscr, 4, (COLS / 2) - 18,
		" :::====  :::====  :::  === :::==== ");
	mvwprintw(stdscr, 5, (COLS / 2) - 18,
		" ::   === :::  === :::  === :::  ===");
	mvwprintw(stdscr, 6, (COLS / 2) - 18,
		"    ====  ===  === ========  ====== ");
	mvwprintw(stdscr, 7, (COLS / 2) - 18,
		"  ===     ===  ===      === ===  ===");
	mvwprintw(stdscr, 8, (COLS / 2) - 18,
		" ========  ======       ===  ====== ");
	mvwprintw(stdscr, 13, (COLS / 2) - 12, "taille grille < %2d x %-2d >",
		env->len, env->len);
}
