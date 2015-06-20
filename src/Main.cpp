/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <qmuntada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:23:12 by frcugy            #+#    #+#             */
/*   Updated: 2015/06/20 16:43:35 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameCore.Class.hpp"
#include "ncurses.h"

int main(void)
{
	int ch;

	initscr();			/* Start curses mode 		*/
	raw();				/* Line buffering disabled	*/
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();			/* Don't echo() while we do getch */

	printw("Type any character to see it in bold\n");
	ch = getch();			/* If raw() hadn't been called
							 * we have to press enter before it
							 * gets to the program 		*/
	if(ch == KEY_F(1))		/* Without keypad enabled this will */
		printw("F1 Key pressed");/*  not get to us either	*/
	/* Without noecho() some ugly escape
	 * charachters might have been printed
	 * on screen			*/
	else
	{	printw("The pressed key is ");
		attron(A_BOLD);
		printw("%c", ch);
		attroff(A_BOLD);
	}
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */

	return (0);
}
