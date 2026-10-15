#ifndef RIDDLES_H
#define RIDDLES_H

#include "Riddle.h"
#include <string>
#include <vector>

class Riddles
{
    private:
    std::vector<Riddle> _Riddles;

    public:
    Riddles();
    std::vector<Riddle> getRiddles();
};

#endif