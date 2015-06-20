/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <qmuntada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:23:12 by frcugy            #+#    #+#             */
/*   Updated: 2015/06/20 20:33:18 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameCore.Class.hpp"
#include <ncurses.h>
#include <unistd.h>

void	signalHandler(int sig)
{
	sig = 0;
	std::cout << "WINDOW RESIZED" << std::endl;
	return ;
}

int main(void)
{
	int ch = 'G';
	clock_t timer;
	GameCore game = GameCore();

	initscr();			/* Start curses mode 		*/
	signal(SIGWINCH, signalHandler);
	start_color();
	noecho();
	cbreak();
	nodelay(stdscr, TRUE); // don't wait for user input
	keypad(stdscr, TRUE);
	curs_set(0);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	while (1)
	{
		game.ftime.FTimeUpdate();
		timer = clock();
		//ProcessUserInput
		//MoveAndAnimateObject
		//DrawTheScene
		//WaitForNextFrame
		ch = getch();
		wclear(stdscr);
		//printw("The pressed key is");
		wrefresh(stdscr);
		usleep(16666 - (game.ftime.deltaTime / CLOCKS_PER_SEC * 100000));
	}
	endwin();
}
