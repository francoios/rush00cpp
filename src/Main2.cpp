#include "GameCore.Class.hpp"
#include <ncurses.h>
#include "Background.Class.hpp"
#include <ctime>
#include "Enemy.Class.hpp"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
	Background	toto;
	char		**map;

	srand(time(NULL));
	map = toto.getTab();
	while (1)
	{
		int i = 0;
		while (i < LINE)
		{
			printf("%s\n",map[i]);
			i++;
		}
		usleep(300000);
		toto.backgroundUpdate();
		map = toto.getTab();
	}
	return (0);
}
