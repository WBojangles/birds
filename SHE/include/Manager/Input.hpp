#ifndef SHE_INPUT
#define SHE_INPUT

#include "../Utility/KeyList.hpp"
#include <SFML/Window.hpp>
#include <map>
#include <string>

	namespace SHE
	{
class Input
{
	friend class InputManager;
	std::map<std::string, SHE::KeyList> actions;
	std::map<sf::Joystick::Axis, float> thresholds;
	int useJoystick;
};
	}

#endif

