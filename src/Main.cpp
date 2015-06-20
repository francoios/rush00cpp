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

void	Animate(void)
{
	;
}



int main(void)
{
	signal(SIGWINCH, signalHandler);
	while (1)
	{
		//UserInput();
		//Animate();
		//DrawScene();
		game.update();
		usleep(16666 - (game.ftime.deltaTime / CLOCKS_PER_SEC * 100000));
	}
	endwin();
}
