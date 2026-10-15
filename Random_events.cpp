#include "Random_events.h"
#include <fstream>
#include <iostream>
#include <string>

std::vector<Event> Random_events::getNegative_events() { return _negative_events; }
std::vector<Event> Random_events::getPositive_events() { return _positive_events; }
std::vector<Event> Random_events::getPath1_events() { return _path1_events; }
std::vector<Event> Random_events::getPath2_events() { return _path2_events; }
std::vector<Event> Random_events::getAll_events() { return _all_events; }

Random_events::Random_events()
{
    std::string line;
    bool is_positive = false;

    std::ifstream events_file("./random_events.txt");

    if(events_file.fail())
    {
        std::cout << "File failed to open" << std::endl;
        return;
    }

    std::string line1;
    std::getline(events_file, line1);
    std::string line2;
    std::getline(events_file, line2);

    while(events_file.good())
    {
        std::getline(events_file, line);
        if(line[0] == '/')
        {
            is_positive = true;
        }
        else
        {
            Event e;
            size_t start_pos = 0;
            size_t delim_pos = line.find('|');

            std::string event = line.substr(start_pos, delim_pos - start_pos);
            e.setEvent(event);
            start_pos = delim_pos + 1;
            delim_pos = line.find('|', start_pos);

            std::string path_type = line.substr(start_pos, delim_pos - start_pos);
            e.setPath_type(std::stoi(path_type));
            start_pos = delim_pos + 1;
            delim_pos = line.find('|', start_pos);

            std::string advisor = line.substr(start_pos, delim_pos - start_pos);
            e.setAdvisor(std::stoi(advisor));
            start_pos = delim_pos + 1;
            delim_pos = line.find('|', start_pos);

            std::string point_outcome = line.substr(start_pos, delim_pos - start_pos);
            e.setPoint_outcome(std::stoi(point_outcome));
        
            if(e.getPath_type() == 0)
            {
                _path1_events.push_back(e);
            }
            else
            {
                _path2_events.push_back(e);
            }
            if(is_positive == true)
            {
                _positive_events.push_back(e);
            }
            else
            {
                _negative_events.push_back(e);
            }
            _all_events.push_back(e);
        }
    }
}