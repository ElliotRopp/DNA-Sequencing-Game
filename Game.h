#ifndef GAME_H
#define GAME_H

#include "Character_in.h"
#include "Riddles.h"
#include "Random_events.h"
#include "Board.h"
#include "Dna.h"


class Game
{
    private:
    Character_in _character_reader;
    Riddles _riddles_reader;
    Random_events _event_reader;
    std::vector<Character> _Character_list;
    std::vector<Event> _Random_events;
    std::vector<Event> _Negative_events;
    std::vector<Event> _Positive_events;
    std::vector<Event> _Path0_events;
    std::vector<Event> _Path1_events;
    std::vector<Riddle> _Riddles;
    Event _event;
    Board board;
    Character _player_1;
    Character _player_2;
    DNA _dna;

    public:
    Game();
    void Run();
    int Main_menu();
    void Character_selection();
    int Path_selection();
    bool Move(int player_index);
    void Advisor_case(int player_index);
    int Spinner();
    void Green_tile(int player_index);
    void Purple_tile(int player_index);
    void Red_tile(int player_index);
    void Blue_tile(int player_index);
    void Brown_tile(int player_index);
    void Pink_tile(int player_index);
    void Calculate_points();    
};

#endif