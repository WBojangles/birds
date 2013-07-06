#undef __STRICT_ANSI__
#include "include/Game.hpp"

int main()
{
	brd::Game game;

	while (game.running())
		game.update();

	return 0;
}
