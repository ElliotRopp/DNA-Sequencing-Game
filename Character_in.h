#ifndef CHARACTER_IN_H
#define CHARACTER_IN_H

#include <string>
#include <vector>
#include "Character.h"


class Character_in
{
    private:
    std::vector<Character> _Characters;

    public:
    Character_in();
    std::vector<Character> getCharacters();
};

#endif