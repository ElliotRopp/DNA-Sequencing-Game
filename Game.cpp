#include "Game.h"

#include <iostream>
#include <fstream>

Game::Game() {}

void Game::Character_selection()
{
    _Character_list = _character_reader.getCharacters();

    int choice_1;
    int choice_2;
    //Player 1 choice
    std::cout << "\nPLAYER 1:\nList of all avalible characters:\n"
        << "playerName|experience|accuracy|efficiency|insight|discoveryPoints\n" 
        << "------------------------------------------------------------------\n";
    
    for(int i = 0; i < _Character_list.size(); i++)
    {
        std::cout << i + 1 << ". ";
        _Character_list[i].printStats();
    }
    std::cin >> choice_1;
    _player_1 = _Character_list[choice_1 - 1];
    _Character_list.erase(_Character_list.begin() + choice_1 - 1);

    _player_1.setPath_type(Path_selection());

    //Player 2 choice
    std::cout << "\nPLAYER 2:\nList of all avalible characters:\n"
        << "playerName|experience|accuracy|efficiency|insight|discoveryPoints\n" 
        << "------------------------------------------------------------------\n";
    
    for(int i = 0; i < _Character_list.size(); i++)
    {
        std::cout << i + 1 << ". ";
        _Character_list[i].printStats();
    }
    std::cin >> choice_2;
    _player_2 = _Character_list[choice_2 - 1];
    _Character_list.erase(_Character_list.begin() + choice_2 - 1); 

    _player_2.setPath_type(Path_selection());
}

int Game::Path_selection()
{
    int path_choice;
    std::cout << "\nPlease chose your path type:\n1. Training Fellowship\n2. Direct Lab Assignment\n";
    std::cin >> path_choice;

    return path_choice - 1;
}

int Game::Main_menu()
{
    int choice;

    std::cout << "\n---MAIN MENU---\n"
        << "1. Player progress\n"
        << "2. Review character\n"
        << "3. Check position\n"
        << "4. Review advisor\n"
        << "5. Move\n"
        << "6. Quit\n";
    std::cin >> choice;

    return choice;
}

void Game::Green_tile(int player_index)
{
    _Random_events = _event_reader.getAll_events();
    _Negative_events = _event_reader.getNegative_events();
    _Positive_events = _event_reader.getPositive_events();
    _Path0_events = _event_reader.getPath1_events();
    _Path1_events = _event_reader.getPath2_events();
    int chance = rand() % 2;
    if(chance == 0)
    {
        std::cout << "No random event" << std::endl;
        return;
    }
    else
    {
        if(player_index == 0)
        {
            int p1_path = _player_1.getPath_type();
            if(p1_path == 0)
            {
                int event_idx = rand() % _Path0_events.size();
                std::string path0_event = _Path0_events[event_idx].getEvent();
                if(_Path0_events[event_idx].getPoint_outcome() < 0)
                {
                    int advisor;
                    if(advisor == _Path0_events[event_idx].getAdvisor())
                    {
                        std::cout << "Your advisor helped! No negative effects" << std::endl;
                    }
                    else
                    {
                        _player_1.setDiscoveryPoints(_player_1.getDiscoveryPoints() + _Path0_events[event_idx].getPoint_outcome());
                    }
                }
                else
                {
                    _player_1.setDiscoveryPoints(_player_1.getDiscoveryPoints() + _Path0_events[event_idx].getPoint_outcome());
                }
                std::cout << "\nRandom event triggered! " << path0_event << "\n" << _Path0_events[event_idx].getPoint_outcome() << " discover points" << std::endl;
            }
            else
            {
                int event_idx = rand() % _Path1_events.size();
                std::string path1_event = _Path1_events[event_idx].getEvent();
                if(_Path1_events[event_idx].getPoint_outcome() < 0)
                {
                    int advisor;
                    if(advisor == _Path1_events[event_idx].getAdvisor())
                    {
                        std::cout << "Your advisor helped! No negative effects" << std::endl;
                    }
                    else
                    {
                        _player_1.setDiscoveryPoints(_player_1.getDiscoveryPoints() + _Path1_events[event_idx].getPoint_outcome());
                    }
                }
                else
                {
                    _player_1.setDiscoveryPoints(_player_1.getDiscoveryPoints() + _Path1_events[event_idx].getPoint_outcome());
                }
                std::cout << "\nRandom event triggered! " << path1_event << "\n" << _Path1_events[event_idx].getPoint_outcome() << " discover points" << std::endl;
            }
        }
        else
        {
            int p2_path = _player_2.getPath_type();
            if(p2_path == 0)
            {
                int event_idx = rand() % _Path0_events.size();
                std::string path0_event = _Path0_events[event_idx].getEvent();
                if(_Path0_events[event_idx].getPoint_outcome() < 0)
                {
                    int advisor;
                    if(advisor == _Path0_events[event_idx].getAdvisor())
                    {
                        std::cout << "Your advisor helped! No negative effects" << std::endl;
                    }
                    else
                    {
                        _player_2.setDiscoveryPoints(_player_2.getDiscoveryPoints() + _Path0_events[event_idx].getPoint_outcome());
                    }
                }
                else
                {
                    _player_2.setDiscoveryPoints(_player_2.getDiscoveryPoints() + _Path0_events[event_idx].getPoint_outcome());
                }
                std::cout << "\nRandom event triggered! " << path0_event << "\n" << _Path0_events[event_idx].getPoint_outcome() << " discover points" << std::endl;
            }
            else
            {
                int event_idx = rand() % _Path1_events.size();
                std::string path1_event = _Path1_events[event_idx].getEvent();
                if(_Path1_events[event_idx].getPoint_outcome() < 0)
                {
                    int advisor;
                    if(advisor == _Path1_events[event_idx].getAdvisor())
                    {
                        std::cout << "Your advisor helped! No negative effects" << std::endl;
                    }
                    else
                    {
                        _player_2.setDiscoveryPoints(_player_2.getDiscoveryPoints() + _Path1_events[event_idx].getPoint_outcome());
                    }
                }
                else
                {
                    _player_2.setDiscoveryPoints(_player_2.getDiscoveryPoints() + _Path1_events[event_idx].getPoint_outcome());
                }
                std::cout << "\nRandom event triggered! " << path1_event << "\n" << _Path0_events[event_idx].getPoint_outcome() << " discover points" << std::endl;
            }
        }
    }
}

void Game::Purple_tile(int player_index)
{
    _Riddles = _riddles_reader.getRiddles();
    std::string answer;
    int riddle_idx = rand() % _Riddles.size();
    std::string question = _Riddles[riddle_idx].getQuestion();

    std::cout << "Your riddle is: " << question << "\nEnter answer (in lowercase): ";
    std::cin >> answer;

    if(answer == _Riddles[riddle_idx].getAnswer())
    {
        if(player_index == 0)
        {
            _player_1.setInsight(_player_1.getInsight() + 500);
            std::cout << "Answer is correct!\n+500 insight" << std::endl;
        }
        else
        {
            _player_2.setInsight(_player_2.getInsight() + 500);
            std::cout << "Answer is correct!\n+500 insight" << std::endl;
        }
    }
    else
    {
        std::cout << "Answer is incorrect" << std::endl;
        return;
    }
}

void Game::Blue_tile(int player_index)
{
    std::string strand;
    std::cout << "\nPlease enter a strand of DNA 5 - 10 letters long in all caps. (A, C, T, G): ";
    std::cin >> strand;
    double sim_score = _dna.strandSim(strand);

    if(sim_score >= 0.7)
    {
        std::cout << "+ 1000 accuracy" << std::endl;
        if(player_index == 0)
        {
            _player_1.setAccuracy(_player_1.getAccuracy() + 1000);
        }
        else
        {
            _player_2.setAccuracy(_player_2.getAccuracy() + 1000);
        }
    }
    else if(sim_score >= 0.4)
    {
        std::cout << "+ 500 accuracy" << std::endl;
        if(player_index == 0)
        {
            _player_1.setAccuracy(_player_1.getAccuracy() + 500);
        }
        else
        {
            _player_2.setAccuracy(_player_2.getAccuracy() + 500);
        }
    }
    else if(sim_score >= 0.2)
    {
        std::cout << "+ 100 accuracy" << std::endl;
        if(player_index == 0)
        {
            _player_1.setAccuracy(_player_1.getAccuracy() + 100);
        }
        else
        {
            _player_2.setAccuracy(_player_2.getAccuracy() + 100);
        }
    }
    else
    {
        std::cout << "No gain" << std::endl;
    }
}

void Game::Pink_tile(int player_index)
{
    std::string strand;
    std::cout << "\nPlease enter a strand of DNA 5 - 10 letters long in all caps. (A, C, T, G): ";
    std::cin >> strand;
    double sim_score = _dna.bestStrandMatch(strand);

    if(sim_score >= 0.75)
    {
        std::cout << "+ 1000 accuracy" << std::endl;
        if(player_index == 0)
        {
            _player_1.setAccuracy(_player_1.getAccuracy() + 1000);
        }
        else
        {
            _player_2.setAccuracy(_player_2.getAccuracy() + 1000);
        }
    }
    else if(sim_score >= 0.4)
    {
        std::cout << "+ 500 accuracy" << std::endl;
        if(player_index == 0)
        {
            _player_1.setAccuracy(_player_1.getAccuracy() + 500);
        }
        else
        {
            _player_2.setAccuracy(_player_2.getAccuracy() + 500);
        }
    }
    else if(sim_score >= 0.2)
    {
        std::cout << "+ 100 accuracy" << std::endl;
        if(player_index == 0)
        {
            _player_1.setAccuracy(_player_1.getAccuracy() + 100);
        }
        else
        {
            _player_2.setAccuracy(_player_2.getAccuracy() + 100);
        }
    }
    else
    {
        std::cout << "No gain" << std::endl;
    }
}

void Game::Brown_tile(int player_index)
{
    std::string strand;
    std::cout << "\nPlease enter a strand of DNA 5 - 10 letters long in all caps. (A, C, T, G): ";
    std::cin >> strand;
    _dna.transcription(strand);
}

void Game::Red_tile(int player_index)
{
    std::string strand;
    std::cout << "\nPlease enter a strand of DNA 10 - 15 letters long in all caps. (A, C, T, G): ";
    std::cin >> strand;
    double sim_score = _dna.idMutation(strand);
    if(sim_score >= 0.7)
    {
        std::cout << "+ 1000 accuracy" << std::endl;
        if(player_index == 0)
        {
            _player_1.setAccuracy(_player_1.getAccuracy() + 1000);
        }
        else
        {
            _player_2.setAccuracy(_player_2.getAccuracy() + 1000);
        }
    }
    else if(sim_score >= 0.4)
    {
        std::cout << "+ 500 accuracy" << std::endl;
        if(player_index == 0)
        {
            _player_1.setAccuracy(_player_1.getAccuracy() + 500);
        }
        else
        {
            _player_2.setAccuracy(_player_2.getAccuracy() + 500);
        }
    }
    else if(sim_score >= 0.2)
    {
        std::cout << "+ 100 accuracy" << std::endl;
        if(player_index == 0)
        {
            _player_1.setAccuracy(_player_1.getAccuracy() + 100);
        }
        else
        {
            _player_2.setAccuracy(_player_2.getAccuracy() + 100);
        }
    }
    else
    {
        std::cout << "No gain" << std::endl;
    }
}

int Game::Spinner()
{
    int random_num = (rand() % 6) + 1;
    std::cout << "Rolled a " << random_num << "!" << std::endl;
    return random_num;
}

bool Game::Move(int player_index)
{
    int roll = Spinner();
    for(int i = 0; i < roll; i++)
    {
        bool done = board.movePlayer(player_index);
        if(done)
        {
            return true;
        }
    }
    std::cout << "You moved " << roll << " places!\n" << std::endl;

    Tile tile = board.getPlayer_tile(player_index);
    if(tile.color == 'G')
    {
        std::cout << "Landed on an event tile!" << std::endl;
        Green_tile(player_index);
    }
    else if(tile.color == 'U')
    {
        std::cout << "Landed on a riddle tile!" << std::endl;
        Purple_tile(player_index);
    }
    else if(tile.color == 'P')
    {
        std::cout << "Landed on a DNA best match tile!" << std::endl;
        Pink_tile(player_index);
    }
    else if(tile.color == 'B')
    {
        std::cout << "Landed on a DNA simalarity tile!" << std::endl;
        Blue_tile(player_index);
    }
    else if(tile.color == 'T')
    {
        std::cout << "Landed on a RNA transcritption tile!" << std::endl;
        Brown_tile(player_index);
    }
    else if(tile.color == 'R')
    {
        std::cout << "Landed on a mutation identification tile!" << std::endl;
        Red_tile(player_index);
    }

    return false;
}

void Game::Advisor_case(int player_index)
{
    if (player_index == 0)
    {
        if (_player_1.getPath_type() == 0)
        {
            int advisor_choice;
            int advisor = _player_1.getAdvisor();
            std::cout << "1. Display advisor's abilites\n2. Display advisor's name" << std::endl;
            std::cin >> advisor_choice;
            switch (advisor_choice)
            {
            case 1:
            {
                if (advisor == 1)
                {
                    std::cout << "A master of the “wet lab”, assisting in avoiding contamination." << std::endl;
                }
                else if (advisor == 2)
                {
                    std::cout << "An expert who helps improve efficiency and streamlines pipelines." << std::endl;
                }
                else if (advisor == 3)
                {
                    std::cout << "A genetics specialist with insight for identifying rare genetic variants." << std::endl;
                }
                else if (advisor == 4)
                {
                    std::cout << "The genius behind the data analysis, helps debug code." << std::endl;
                }
                else if (advisor == 5)
                {
                    std::cout << "Your biggest supporter assisting you in learning the equipment" << std::endl;
                }
                break;
            }
            case 2:
            {
                if (advisor == 1)
                {
                    std::cout << "Dr. Aliquot" << std::endl;
                }
                else if (advisor == 2)
                {
                    std::cout << "Dr. Assembler" << std::endl;
                }
                else if (advisor == 3)
                {
                    std::cout << "Dr. Pop-Gen" << std::endl;
                }
                else if (advisor == 4)
                {
                    std::cout << "Dr. Bio-Script" << std::endl;
                }
                else if (advisor == 5)
                {
                    std::cout << "Dr. Loci" << std::endl;
                }
                break;
            }
            default:
                std::cout << "Invalid option" << std::endl;
            }
        }
        else
        {
            std::cout << "You don't have an advisor" << std::endl;
        }
    }
    else
    {
        if (_player_2.getPath_type() == 0)
        {
            int advisor_choice;
            int advisor = _player_2.getAdvisor();
            std::cout << "1. Display advisor's abilites\n2. Display advisor's name" << std::endl;
            std::cin >> advisor_choice;
            switch (advisor_choice)
            {
            case 1:
            {
                if (advisor == 1)
                {
                    std::cout << "A master of the “wet lab”, assisting in avoiding contamination." << std::endl;
                }
                else if (advisor == 2)
                {
                    std::cout << "An expert who helps improve efficiency and streamlines pipelines." << std::endl;
                }
                else if (advisor == 3)
                {
                    std::cout << "A genetics specialist with insight for identifying rare genetic variants." << std::endl;
                }
                else if (advisor == 4)
                {
                    std::cout << "The genius behind the data analysis, helps debug code." << std::endl;
                }
                else if (advisor == 5)
                {
                    std::cout << "Your biggest supporter assisting you in learning the equipment" << std::endl;
                }
                break;
            }
            case 2:
            {
                if (advisor == 1)
                {
                    std::cout << "Dr. Aliquot" << std::endl;
                }
                else if (advisor == 2)
                {
                    std::cout << "Dr. Assembler" << std::endl;
                }
                else if (advisor == 3)
                {
                    std::cout << "Dr. Pop-Gen" << std::endl;
                }
                else if (advisor == 4)
                {
                    std::cout << "Dr. Bio-Script" << std::endl;
                }
                else if (advisor == 5)
                {
                    std::cout << "Dr. Loci" << std::endl;
                }
                break;
            }
            default:
                std::cout << "Invalid option" << std::endl;
            }
        }
        else
        {
            std::cout << "You don't have an advisor" << std::endl;
        }
    }
}

void Game::Calculate_points()
{
    std::ofstream out_file("./Summary.txt", std::ios::app);

    _player_1.setDiscoveryPoints(_player_1.getDiscoveryPoints() + (_player_1.getAccuracy() / 100) * 1000);
    _player_1.setDiscoveryPoints(_player_1.getDiscoveryPoints() + (_player_1.getEfficiency() / 100) * 1000);
    _player_1.setDiscoveryPoints(_player_1.getDiscoveryPoints() + (_player_1.getInsight() / 100) * 1000);

    _player_2.setDiscoveryPoints(_player_2.getDiscoveryPoints() + (_player_2.getAccuracy() / 100) * 1000);
    _player_2.setDiscoveryPoints(_player_2.getDiscoveryPoints() + (_player_2.getEfficiency() / 100) * 1000);
    _player_2.setDiscoveryPoints(_player_2.getDiscoveryPoints() + (_player_2.getInsight() / 100) * 1000);

    if(_player_1.getDiscoveryPoints() > _player_2.getDiscoveryPoints())
    {
        std::cout << "Player 1 wins with " << _player_1.getDiscoveryPoints() << " discover points!" << std::endl;
        out_file << "Player 1 wins with " << _player_1.getDiscoveryPoints() << " discover points!" << std::endl;
    }
    else if(_player_2.getDiscoveryPoints() > _player_1.getDiscoveryPoints())
    {
        std::cout << "Player 2 wins with " << _player_2.getDiscoveryPoints() << " discover points!" << std::endl;
        out_file  << "Player 2 wins with " << _player_2.getDiscoveryPoints() << " discover points!" << std::endl;
    }
    else if(_player_1.getDiscoveryPoints() == _player_2.getDiscoveryPoints())
    {
        std::cout << "It's a tie! both players have " << _player_1.getDiscoveryPoints() << "\n'";
        out_file << "It's a tie! both players have " << _player_1.getDiscoveryPoints() << "\n";
    }

    out_file << "Player 1: " << _player_1.getPlayer_name() << "|" << _player_1.getDiscoveryPoints() << "\n"
        << "Player 2: " << _player_2.getPlayer_name() << "|" << _player_2.getDiscoveryPoints() 
        << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< std::endl;
}

void Game::Run()
{
    Character_selection();

    bool player_1_done = false;
    bool player_2_done = false;
    bool game_running = true;
    while(game_running)
    {
        bool p1_turn = true;
        while(p1_turn && !player_1_done)
        {
            //player 1 turn
            std::cout << "\nPLAYER 1:" << std::endl;
            int menu_choice_p1 = Main_menu();
            switch(menu_choice_p1)
            {
                case 1: 
                {
                    int progress_choice;
                    std::cout << "1. Review discovery points\n2. Review Stats" << std::endl;
                    std::cin >> progress_choice;
                    switch(progress_choice)
                    {
                        case 1: std::cout << "Discovery points: " << _player_1.getDiscoveryPoints() << std::endl; break;
                        case 2: std::cout << "All trait stats: "; _player_1.printStats(); break; 
                        default: std::cout << "Invalid option" << std::endl;
                    }
                    break;
                }
                case 2: _player_1.printStats(); break;
                case 3: board.displayBoard(); break;
                case 4: Advisor_case(0); break;
                case 5: player_1_done = Move(0); p1_turn = false; break;
                case 6: game_running = false; p1_turn = false; break;
                default: std::cout << "Invalid choice" << std::endl; break;
            }
        }
        if(game_running == false)
        {
            break;
        }
        if(player_1_done == true)
        {
            std::cout << "Player 1 reached the finish!" << std::endl;
        }
        bool p2_turn = true;
        //player 2 turn
        while(p2_turn && !player_2_done)
        {
            std::cout << "\nPLAYER 2:" << std::endl;
            int menu_choice_p2 = Main_menu();
            switch(menu_choice_p2)
            {
                case 1: 
                {
                    int progress_choice;
                    std::cout << "1. Review discovery points\n2. Review Stats" << std::endl;
                    std::cin >> progress_choice;
                    switch(progress_choice)
                    {
                        case 1: std::cout << "Discovery points: " << _player_2.getDiscoveryPoints() << std::endl; break;
                        case 2: std::cout << "All trait stats: "; _player_2.printStats(); break; 
                        default: std::cout << "Invalid option" << std::endl;
                    }
                }
                case 2: _player_2.printStats(); break;
                case 3: board.displayBoard(); break;
                case 4: Advisor_case(1); break;
                case 5: player_2_done = Move(1); p2_turn = false; break;
                case 6: game_running = false; p2_turn = false; break;
                default: std::cout << "Invalid choice" << std::endl; break;
            }
        }
        if(game_running == false)
        {
            break;
        }
        if(player_2_done == true)
        {
            std::cout << "Player 2 reached the finish!" << std::endl;
        }
        board.displayBoard();

        if(player_1_done == true && player_2_done == true)
        {
            game_running = false;
            break;
        }
    }
    Calculate_points();
}