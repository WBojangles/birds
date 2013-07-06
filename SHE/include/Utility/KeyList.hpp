#ifndef SHE_KEYLIST
#define SHE_KEYLIST

#include <SFML/Window.hpp>
#include <vector>
#include <map>

	namespace SHE
	{
class KeyList
{
  public:
	std::vector<sf::Keyboard::Key> keyList;
	std::vector<sf::Mouse::Button> mouseList;
	std::vector<int> joyList;
	std::map<sf::Joystick::Axis, bool> axisMap;

  private:
};
	}

#endif
