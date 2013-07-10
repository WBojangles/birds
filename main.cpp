#undef __STRICT_ANSI__
#include "include/Game.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	brd::Game game;
    std::srand(std::time(0));

	while (game.running())
		game.update();

	return 0;
}
