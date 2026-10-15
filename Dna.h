#ifndef DNA_H
#define DNA_H

#include <string>

class DNA
{
    private:

    public:
    std::string randomStrand(int strand_in_length);
    double strandSim(std::string strand_1);
    double bestStrandMatch(std::string strand_1);
    void transcription(std::string strand_1);
    double idMutation(std::string strand_1);
};

#endif