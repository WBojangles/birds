#ifndef SHE_INPUTMANAGER
#define SHE_INPUTMANAGER

#include "Input.hpp"
#include <map>

#include <iostream>

	namespace SHE
	{
class InputManager
{
  public:
	static void setPlayers(const int&);
	static void bind(const int&, const std::string&, const sf::Keyboard::Key&);
	static void bind(const int&, const std::string&, const sf::Mouse::Button&);
	static void bind(const int&, const std::string&, const int&);
	static void bind(const int&, const std::string&, const sf::Joystick::Axis&, const bool&);
	static void unbindAll(const int&);
	static void setThreshold(const int&, const sf::Joystick::Axis, const float&);
	static void setJoystick(const int&, const int&);
	static bool check(const int&, const std::string&);

  private:
	static int players;
	static std::map<int, SHE::Input> inputs;
};
	}

#endif
