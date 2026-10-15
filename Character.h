#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{
    private:
    std::string _player_name;
    int _experience = 0;
    int _accuracy = 0;
    int _efficiency = 0;
    int _insight = 0;
    int _discoveryPoints = 0;
    int _path_type = 0;
    int _advisor = 0;

    public:
    Character();

    std::string getPlayer_name();
    int getExperience();
    int getAccuracy();
    int getEfficiency();
    int getInsight();
    int getDiscoveryPoints();
    int getPath_type();
    int getAdvisor();
        
    void setPlayer_name(std::string name);
    void setExperience(int experience);
    void setAccuracy(int accuracy);
    void setEfficieny(int efficiency);
    void setInsight(int insight);
    void setDiscoveryPoints(int discoveryPoints);
    void setPath_type(int path_type);
    void setAdvisor(int advisor);

    void printStats();
};

#endif