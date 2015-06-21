#include "GameCore.Class.hpp"
#include <ncurses.h>
#include <unistd.h>

# define SPACE 32
# define ESC 27


static GameCore game = GameCore();

void	signalHandler(int sig)
{
	(void)sig;
	game.screen.updateSize();
	return ;
}

void	UserInput() {
	game.player.setFire(false);
	game.player.setAxeH(0);

	int key_press = getch();
	if (key_press == KEY_RIGHT)
		game.player.setAxeH(1);
	else if (key_press == SPACE)
		game.player.setFire(true);
	else if (key_press == KEY_LEFT)
		game.player.setAxeH(-1);
	else if (key_press == ESC)
		exit(0);
}


void	Animate(void)
{
	char	**array;
	int		c = -1;
	array = game.decor.getTab();
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
		UserInput();
		Animate();
		//DrawScene();
		game.update();
		usleep(16666 - (game.ftime.deltaTime / CLOCKS_PER_SEC * 100000));
	}
	endwin();
}
