#include "Character_in.h"
#include <fstream>
#include <string>
#include <iostream>

std::vector<Character> Character_in::getCharacters() { return _Characters; }

Character_in::Character_in()
{
    std::string line;

    std::ifstream character_file("./characters.txt");

    if(character_file.fail())
    {
        std::cout << "File failed to open" << std::endl;
        return;
    }

    std::string line1;
    std::getline(character_file, line1);

    while(character_file.good())
    {
        std::getline(character_file, line);
        Character c;
        size_t start_pos = 0;
        size_t delim_pos = line.find('|');

        std::string name = line.substr(start_pos, delim_pos - start_pos);
        c.setPlayer_name(name);
        start_pos = delim_pos + 1;
        delim_pos = line.find('|', start_pos);

        std::string exp = line.substr(start_pos, delim_pos - start_pos);
        c.setExperience(std::stoi(exp));
        start_pos = delim_pos + 1;
        delim_pos = line.find('|', start_pos);

        std::string accuracy = line.substr(start_pos, delim_pos - start_pos);
        c.setAccuracy(std::stoi(accuracy));
        start_pos = delim_pos + 1;
        delim_pos = line.find('|', start_pos);

        std::string efficiency = line.substr(start_pos, delim_pos - start_pos);
        c.setEfficieny(std::stoi(efficiency));
        start_pos = delim_pos + 1;
        delim_pos = line.find('|', start_pos);
        
        std::string insight = line.substr(start_pos, delim_pos - start_pos);
        c.setInsight(std::stoi(insight));
        start_pos = delim_pos + 1;
        delim_pos = line.find('|', start_pos);

        std::string discoveryPoints = line.substr(start_pos, delim_pos - start_pos);
        c.setDiscoveryPoints(std::stoi(discoveryPoints));

        _Characters.push_back(c);
    }
}