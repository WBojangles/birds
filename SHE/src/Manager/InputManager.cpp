#include "../../include/Manager/InputManager.hpp"

// Static members
int SHE::InputManager::players = 0;
std::map<int, SHE::Input> SHE::InputManager::inputs = std::map<int, SHE::Input>();

// Update the number of players
void SHE::InputManager::setPlayers(const int& n)
{
	if (n > players) // If adding players...
	{
		for (; players < n; players++) // For each additional player...
		{
			inputs[players + 1] = SHE::Input(); // Throw another input in the inputs vector
			inputs[players + 1].useJoystick = players; // Assume player is using their position of joystick
		}
	}
	else if (n < players) // Or subtracting...
	{
		for (; players > n; players--)
			inputs.erase(players);
	}
}

// Bind a keyboard key
void SHE::InputManager::bind(const int& player, const std::string& action, const sf::Keyboard::Key& key)
{
	if (inputs.find(player) != inputs.end())
		inputs[player].actions[action].keyList.push_back(key);
	// TODO: else error
}

// Bind a mouse button
void SHE::InputManager::bind(const int& player, const std::string& action, const sf::Mouse::Button& button)
{
	if (inputs.find(player) != inputs.end())
		inputs[player].actions[action].mouseList.push_back(button);
	// TODO: else error
}

// Bind a joystick button
void SHE::InputManager::bind(const int& player, const std::string& action, const int& button)
{
	if (inputs.find(player) != inputs.end())
	{
		inputs[player].actions[action].joyList.push_back(button);
		std::cout << "Binding \"" << action << "\" to button " << button << " for player " << player << ".\n";
	}
	// TODO: else error

}

void SHE::InputManager::bind(const int& player, const std::string& action, const sf::Joystick::Axis& axis, const bool& positive)
{
	if (inputs.find(player) != inputs.end())
	{
		inputs[player].actions[action].axisMap[axis] = positive;
		std::cout << "Binding \"" << action << "\" to axis X for player " << player << ".\n";
	}
	// TODO: else error
}

// Unbind all keys for a player
void SHE::InputManager::unbindAll(const int& player)
{
	if (inputs.find(player) != inputs.end())
	{
		inputs[player].actions.clear();
	}
}

void SHE::InputManager::setThreshold(const int& player, const sf::Joystick::Axis axis, const float& threshold)
{
	if (inputs.find(player) != inputs.end())
		inputs[player].thresholds[axis] = threshold;
	// TODO: else error
}

// Associate a joystick with a player
void SHE::InputManager::setJoystick(const int& player, const int& joystick)
{
	if (inputs.find(player) != inputs.end())
		inputs[player].useJoystick = joystick;
	// TODO: else error
}

// Check if an action should be triggered
bool SHE::InputManager::check(const int& player, const std::string& action)
{
	if (inputs.find(player) != inputs.end())
	{
		SHE::KeyList current = inputs[player].actions[action];
		// Check keyboard
		for (unsigned int i = 0; i < current.keyList.size(); i++)
		{
			if (sf::Keyboard::isKeyPressed(current.keyList[i]))
				return true;
		}

		// Check mouse
		for (unsigned int i = 0; i < current.mouseList.size(); i++)
		{
			if (sf::Mouse::isButtonPressed(current.mouseList[i]))
				return true;
		}

		// Check joystick
		for (unsigned int i = 0; i < current.joyList.size(); i++)
		{
			if (sf::Joystick::isButtonPressed(player-1, current.joyList[i]))
				return true;
		}

		// Check joystick axis
		std::map<sf::Joystick::Axis, bool>::iterator it;
		for (it = current.axisMap.begin(); it != current.axisMap.end(); it++)
		{
			float thresh = inputs[player].thresholds[it->first];
			if (it->second) // If threshold is positive
			{
				if (sf::Joystick::getAxisPosition(inputs[player].useJoystick, it->first) > thresh)
					return true;
			}
			else // Threshold is negative
			{
				if (sf::Joystick::getAxisPosition(inputs[player].useJoystick, it->first) < -1.f * thresh)
					return true;
			}
		}
	}
	// TODO: else error

	// Nope!
	return false;
}
