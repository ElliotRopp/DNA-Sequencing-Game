#include "Riddles.h"
#include <fstream>
#include <string>
#include <iostream>

std::vector<Riddle> Riddles::getRiddles() { return _Riddles; }

Riddles::Riddles()
{
    std::string line;

    std::ifstream riddles_file("./riddles.txt");

    if(riddles_file.fail())
    {
        std::cout << "File failed to open" << std::endl;
        return;
    }

    std::string line1;
    std::getline(riddles_file, line1);

    while(riddles_file.good())
    {
        std::getline(riddles_file, line);
        Riddle r;
        size_t start_pos = 0;
        size_t delim_pos = line.find('|');

        std::string question = line.substr(start_pos, delim_pos - start_pos);
        r.setQuestion(question);
        start_pos = delim_pos + 1;
        delim_pos = line.find('|', start_pos);

        std::string answer = line.substr(start_pos, delim_pos - start_pos);
        r.setAnswer(answer);

        _Riddles.push_back(r);
    }
}