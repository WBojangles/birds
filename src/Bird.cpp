#include "../include/Bird.hpp"

const int brd::Bird::NUM_NAMES = 58;

brd::Bird::Bird()
{
    std::ifstream eat_it;
    std::string line;
    int namenum = std::rand() % NUM_NAMES;
    eat_it.open(".assets/birdnames");
    if (eat_it.is_open())
    {
    	int it = 0;
        while (std::getline(eat_it, line))
        {
        	if (it == namenum)
        	{
        		gnd = *line.rbegin();
        		name = line.erase(line.find_first_of(" "), std::string::npos);
        		break;
        	}
			it++;
        }
    }
}

void brd::Bird::setDialogue(const int& track)
{
	dgTrack = track;
}

void brd::Bird::nextText()
{
}
