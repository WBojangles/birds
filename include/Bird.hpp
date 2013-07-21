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
    void setDialogue(const int&);
    void nextText();

    std::string name;
    char gnd;

  private:
    static const int NUM_NAMES;
    int dgTrack;
};
    }

#endif
