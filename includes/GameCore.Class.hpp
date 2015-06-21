#ifndef GAMECORE_CLASS_HPP
# define GAMECORE_CLASS_HPP
# include <iostream>
# include "FTime.Class.hpp"
# include "Screen.Class.hpp"
# include "Background.Class.hpp"
# include "Enemy.Class.hpp"
# include "Player.Class.hpp"
# include "User.Class.hpp"

# define ENEMYNB 6

class GameCore {
public:
	GameCore();
	GameCore(GameCore const & rhs);
	~GameCore();

	GameCore const &	operator=(GameCore const & rhs);
	void				update(void);

	Screen		screen; // Window handling
	FTime		ftime; // Time/frame handling
	Background	decor;
	Player		player;
	Enemy		enemy[ENEMYNB];
	User		user;
	// ICI TOUTES LES CLASSE PRATIQUE COMME SCREEN, TIME, QUI
	// SERONT AINSI ACCESSIBLE GRACE A L'INSTANCE DE GAMECORE

private:

protected:

};

#endif
