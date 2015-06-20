#include "GameCore.Class.hpp"
#include <ncurses.h>
#include <unistd.h>

static GameCore game = GameCore();

void	signalHandler(int sig)
{
	(void)sig;
	game.screen.updateSize();
	return ;
}

int main(void)
{
	int ch = 'G';
	signal(SIGWINCH, signalHandler);
	while (1)
	{
		//ProcessUserInput
		//MoveAndAnimateObject
		//DrawTheScene
		//WaitForNextFrame
		ch = getch();
		printw("The pressed key is ");
		printw("%d\n", ch);
		game.update();
		usleep(16666 - (game.ftime.deltaTime / CLOCKS_PER_SEC * 100000));
	}
	endwin();
}
