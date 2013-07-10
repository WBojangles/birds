#ifndef BRD_BIRD
#define BRD_BIRD

#include <string>
#include <cstdlib>
#include <fstream>

    namespace brd
    {
class Bird
{
  public:
    Bird();
    std::string name;

  private:
    static const int NUM_NAMES;
}
    }

#endif
