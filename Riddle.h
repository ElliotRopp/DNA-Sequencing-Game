#ifndef RIDDLE_H
#define RIDDLE_H

#include <string>

class Riddle
{
    private:
    std::string _question;
    std::string _answer;

    public:
    Riddle();
    std::string getQuestion();
    std::string getAnswer();
    
    void setQuestion(std::string question);
    void setAnswer(std::string answer);

    void printRiddles();
};

# endif