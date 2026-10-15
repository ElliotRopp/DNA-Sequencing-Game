#include "Event.h"
#include <iostream>

Event::Event() {}

std::string Event::getEvent() { return _event; }
int Event::getPath_type() { return _path_type; }
int Event::getAdvisor() { return _advisor; }
int Event::getPoint_outcome() { return _point_outcome; }

void Event::setEvent(std::string event) { _event = event; }
void Event::setPath_type(int path_type) { _path_type = path_type; }
void Event::setAdvisor(int advisor) {_advisor = advisor; }
void Event::setPoint_outcome(int point_outcome) { _point_outcome = point_outcome; }

void Event::print_negative_events()
{
    std::cout << _event << "|" << _path_type << "|" << _advisor << "|" << _point_outcome << std::endl;
}
void Event::print_positive_events()
{
    std::cout << _event << "|" << _path_type << "|" << _advisor << "|" << _point_outcome << std::endl;
}