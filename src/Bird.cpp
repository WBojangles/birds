#include "../include/Bird.hpp"

const int brd::Bird::NUM_NAMES = 58

brd::Bird::Bird()
{
    std::ifstream eat_it;
    std::string line;
    eat_it.open(".assets/birdnames");
    if (eat_it.is_open())
    {
        while (eat_it.good())
        {
            std::getline(eat_it, line);//jkoji0ipjlSUPER CODE ACTIVATE
        }
    }
}
