#ifndef EVENT_H
#define EVENT_H

#include <string>

class Event
{
    private:
    std::string _event;
    int _path_type;
    int _advisor;
    int _point_outcome;

    public:
    Event();
    std::string getEvent();
    int getPath_type();
    int getAdvisor();
    int getPoint_outcome();

    void setEvent(std::string event);
    void setPath_type(int path_type);
    void setAdvisor(int advisor);
    void setPoint_outcome(int point_outcome);

    void print_negative_events();
    void print_positive_events();
};

#endif