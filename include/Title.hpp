#ifndef BRD_TITLE
#define BRD_TITLE

#include "../SHE/include/State/State.hpp"
#include "../SHE/include/Manager/StateManager.hpp"
#include "../SHE/include/Manager/AssetManager.hpp"
#include "../SHE/include/Manager/InputManager.hpp"
#include "Play.hpp"
#include <tr1/memory>

    namespace brd
    {
class Title : public SHE::State
{
  public:
    void init();
    void reInit();
    void doEvents(const sf::Event&);
    void update(const float&);
    void draw();
    void clean();

  private:
    sf::Sprite bg;
};
    }

#endif
