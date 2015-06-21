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
	char	**array = new char * [LINE];
	int		c = -1;
	while (++c < LINE)
		array[c] = new char [COL];
	array = game.decor.getTab();
	c = -1;
	while (++c < LINE)
	{
		printw("%s\n", array[c]);
	}
	return ;
}



int main(void)
{
	signal(SIGWINCH, signalHandler);
	while (1)
	{
		//UserInput();
		Animate();
		//DrawScene();
		game.update();
		usleep(16666 - (game.ftime.deltaTime / CLOCKS_PER_SEC * 100000));
	}
	endwin();
}
