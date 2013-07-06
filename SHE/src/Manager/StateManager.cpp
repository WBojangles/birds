#include "../../include/Manager/StateManager.hpp"

typedef std::tr1::shared_ptr<SHE::State> StateSP;

// Static members
SHE::StateMap SHE::StateManager::stateMap = SHE::StateMap();
bool SHE::StateManager::quit = false;
sf::RenderWindow SHE::StateManager::window;

void SHE::StateManager::create(const std::string& gamestate, StateSP state)
{
	stateMap.states[gamestate] = state;
	stateMap.statesInit[gamestate] = false;
}

void SHE::StateManager::set(const std::string& gamestate)
{
	if (stateMap.states.count(gamestate)) // If there is a "gamestate" in states
	{
		stateMap.states[stateMap.active]->clean();
		stateMap.active = gamestate;
		if (!stateMap.statesInit[stateMap.active])
		{
			stateMap.states[stateMap.active]->init();
			stateMap.statesInit[stateMap.active] = true;
		}
		else
			stateMap.states[stateMap.active]->reInit();
	}
	// TODO: else error

	std::cout << "Set state to " << gamestate << "\n";
}

void SHE::StateManager::clean(const std::string& gamestate)
{
	if (stateMap.active != gamestate) // Don't clean the currently active state! Wait, actually is that a good idea?
		stateMap.states[gamestate]->clean();
	// TODO: else error
}

void SHE::StateManager::remove(const std::string& gamestate)
{
	if (stateMap.active != gamestate) // Well at least THIS is definitely a good idea.
	{
		stateMap.states[gamestate]->clean();
		stateMap.states.erase(gamestate);
		stateMap.statesInit.erase(gamestate);
	}
}

void SHE::StateManager::events(const sf::Event& E)
{
	stateMap.states[stateMap.active]->doEvents(E);
}

void SHE::StateManager::update(const float& frametime)
{
	stateMap.states[stateMap.active]->update(frametime);
}

void SHE::StateManager::draw()
{
	stateMap.states[stateMap.active]->draw();
}
