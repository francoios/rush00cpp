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
	char	**array;
	int		c = -1;
	// FIN INIT ARRAY

	array = game.decor.getTab();

	// FIN GET DU DECOR

	c = -1;
	while (++c < LINE)
	{
		mvprintw(c, 0, "%s\n", array[c]);
	}
	// FIN AFFICHAGE
	return ;
}



int main(void)
{
	signal(SIGWINCH, signalHandler);
	while (1)
	{
		//UserInput();
		if (game.screen.isWellSized)
		{
			//UserInput();
			Animate();
			//DrawScene();
			game.update();
		}
		usleep(16666 - (game.ftime.deltaTime / CLOCKS_PER_SEC * 100000));
	}
	endwin();
}
