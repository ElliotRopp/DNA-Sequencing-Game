#include "Character.h"
#include<iostream>

Character::Character() {}

std::string Character::getPlayer_name() { return _player_name; }
int Character::getExperience() { return _experience; }
int Character::getAccuracy() { return _accuracy; }
int Character::getEfficiency() {return _efficiency; }
int Character::getInsight() { return _insight; }
int Character::getDiscoveryPoints() { return _discoveryPoints; }
int Character::getPath_type() { return _path_type; }
int Character::getAdvisor() { return _advisor; }

void Character::setPlayer_name(std::string name) { _player_name = name; }
void Character::setExperience(int exp) { _experience = exp; }
void Character::setAccuracy(int accuracy) 
{ 
    _accuracy = accuracy; 
    if(_accuracy < 100)
    {
        _accuracy = 100;
    }
}
void Character::setEfficieny(int efficiency) 
{
    _efficiency = efficiency; 
    if(_efficiency < 100)
    {
        _efficiency = 100;
    }
}
void Character::setInsight(int insight) 
{ 
    _insight = insight;
    if(_insight < 100)
    {
        _insight = 100;
    } 
}
void Character::setDiscoveryPoints(int discoveryPoints) { _discoveryPoints = discoveryPoints; }

void Character::setPath_type(int path_type)
{
    _path_type = path_type;

    if(_path_type == 1)
    {
        setAccuracy(_accuracy + 200);
        setEfficieny(_efficiency + 200);
        setInsight(_insight + 200);
        setDiscoveryPoints(_discoveryPoints + 5000);
        setAdvisor(0);
    }
    else
    {
        int advisor_choice;
        std::cout << "\nPlease select your advidor:\n"
            << "1. Dr. Aliquot - A master of the 'wet lab', assisting in avoiding contamination.\n"
            << "2. Dr. Assembler - An expert who helps improve efficiency and streamlines pipelines.\n"
            << "3. Dr. Pop-Gen - A genetics specialist with insight for identifying rare genetic variants.\n"
            << "4. Dr. Bio-Script - The genius behind the data analysis, helps debug code.\n"
            << "5. Dr. Loci - Your biggest supporter assisting you in learning the equipment\n";
        std::cin >> advisor_choice;
        setAccuracy(_accuracy + 500);
        setEfficieny(_efficiency + 500);
        setInsight(_insight + 1000);
        setDiscoveryPoints(_discoveryPoints - 5000);
        setAdvisor(advisor_choice);
    }
}
void Character::setAdvisor(int advisor) { _advisor = advisor; }

void Character::printStats()
{
    std::cout << _player_name << "|"  << _experience << "|" << _accuracy
        << "|" << _efficiency << "|" << _insight << std::endl;
}