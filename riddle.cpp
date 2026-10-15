#include "Riddle.h"
#include <iostream>

Riddle::Riddle() {}

std::string Riddle::getQuestion() { return _question; }
std::string Riddle::getAnswer() { return _answer; }

void Riddle::setQuestion(std::string question) { _question = question; }
void Riddle::setAnswer(std::string answer) { _answer = answer; }

void Riddle::printRiddles()
{
    std::cout << _question << "|" << _answer << std::endl;
}
