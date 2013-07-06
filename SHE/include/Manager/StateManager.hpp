#ifndef SHE_STATEMANAGER
#define SHE_STATEMANAGER

#include "StateMap.hpp"
#include <SFML/Graphics.hpp>
#include <tr1/memory>

#include <iostream>

	namespace SHE
	{
class StateManager
{
  public:
	static void create(const std::string&, std::tr1::shared_ptr<SHE::State>);
	static void set(const std::string&);
	static void clean(const std::string&);
	static void remove(const std::string&);
	static void events(const sf::Event&);
	static void update(const float&);
	static void draw();
	static bool quit;
	static sf::RenderWindow window;

  private:
	static StateMap stateMap;
};
	}

#endif
