#ifndef SHE_STATE
#define SHE_STATE

#include <SFML/Graphics.hpp>

	namespace SHE
	{
class State
{
  public:
	virtual void init() = 0;
	virtual void reInit() = 0;
	virtual void doEvents(const sf::Event&) = 0;
	virtual void update(const float&) = 0;
	virtual void draw() = 0;
	virtual void clean() = 0;

  private:
};
	}

#endif
