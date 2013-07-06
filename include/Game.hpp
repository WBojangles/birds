#ifndef BRD_GAME
#define BRD_GAME

#include "../SHE/include/State/State.hpp"
#include "../SHE/include/Manager/StateManager.hpp"
#include "../SHE/include/Manager/InputManager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <tr1/memory>

	namespace brd
	{
class Game
{
  public:
	Game();
	bool running();
	void update();
	void draw();

  private:
	sf::Clock delta;
};
	}

#endif
