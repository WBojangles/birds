#ifndef BRD_PLAY
#define BRD_PLAY

#include "../SHE/include/State/State.hpp"
#include "../SHE/include/Manager/StateManager.hpp"
#include "../SHE/include/Manager/AssetManager.hpp"

    namespace brd
    {
class Play : public SHE::State
{
  public:
    void init();
    void reInit();
    void doEvents(const sf::Event&);
    void update(const float&);
    void draw();
    void clean();

  private:
};
    }

#endif
