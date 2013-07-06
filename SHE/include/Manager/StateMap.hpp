#ifndef SHE_STATEMAP
#define SHE_STATEMAP

#include "../State/State.hpp"
#include "../State/DefaultState.hpp"
#include <map>
#include <string>
#include <tr1/memory>

	namespace SHE
	{
class StateMap
{
	friend class StateManager;
	std::map<std::string, std::tr1::shared_ptr<SHE::State> > states;
	std::map<std::string, bool> statesInit;
	std::string active;

	StateMap()
	{
		active = "DefaultState";
		states[active] = std::tr1::shared_ptr<SHE::State>(new SHE::DefaultState());
		statesInit[active] = false;
	}
};
	}

#endif
