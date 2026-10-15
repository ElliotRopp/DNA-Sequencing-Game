#ifndef RANDOM_EVENTS_H
#define RANDOM_EVENTS_H

#include "Event.h"
#include <string>
#include <vector>

class Random_events
{
    private:
    std::vector<Event> _negative_events;
    std::vector<Event> _positive_events;
    std::vector<Event> _path1_events;
    std::vector<Event> _path2_events;
    std::vector<Event> _all_events;

    public:
    Random_events();
    std::vector<Event> getNegative_events();
    std::vector<Event> getPositive_events();
    std::vector<Event> getPath1_events();
    std::vector<Event> getPath2_events();
    std::vector<Event> getAll_events();
};

#endif