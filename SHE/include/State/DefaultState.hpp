#ifndef SHE_DEFAULTSTATE
#define SHE_DEFAULTSTATE

#include "State.hpp"

	namespace SHE
	{
class DefaultState : public SHE::State
{
  public:
	void init() {}
	void reInit() {}
	void doEvents(const sf::Event&) {}
	void update(const float&) {}
	void draw() {}
	void clean() {}

  private:
};
	}

#endif
