#include "Dna.h"

#include <iostream>
#include <iomanip>

std::string DNA::randomStrand(int strand_in_length)
{
    std::string strand;
    for(int i = 0; i < strand_in_length; i++)
    {
        int random = rand() % 4;
        switch(random)
        {
            case 0: strand.push_back('A'); break;
            case 1: strand.push_back('C'); break;
            case 2: strand.push_back('T'); break;
            case 3: strand.push_back('G'); break;
        }
    }
    return strand;
}

double DNA::strandSim(std::string strand_1)
{
    std::string strand_2 = randomStrand(strand_1.length());
    std::cout << "\nRandom strand: " << strand_2 << std::endl;
    int matches = 0;
    int pos = strand_1.length();
    for(int i = 0; i < strand_1.length(); i++)
    {
        if(strand_1[i] == strand_2[i])
        {
            matches += 1;
        }
    }
    double sim = static_cast<double> (matches) / pos;

    std::cout << std::fixed << std::setprecision(3) << "Similarity of " << sim << std::endl;

    return sim;
}

double DNA::bestStrandMatch(std::string strand_1)
{
    std::string strand_2 = randomStrand(strand_1.length() * 3);
    std::cout << "\nRandom strand: " << strand_2 << std::endl;
    int matches = 0;
    double best_sim = 0;
    int best_index = 0;
    int pos = strand_1.length();
    for(int j = 0; j < strand_2.length() - strand_1.length(); j++)
    {
        matches = 0;
        for (int i = 0; i < strand_1.length(); i++)
        {
            if (strand_1[i] == strand_2[i + j])
            {
                matches += 1;
            }
        }
        double sim = static_cast<double>(matches) / pos;
        if(sim > best_sim)
        {
            best_sim = sim;
            best_index = j;
        }
    }

    std::cout << std::fixed << std::setprecision(3) << "Best match at position " << best_index + 1 << " With a similarity of " << best_sim << std::endl;

    return best_sim;
}

void DNA::transcription(std::string strand_1)
{
    for(int i = 0; i < strand_1.length(); i++)
    {
        if(strand_1[i] == 'T')
        {
            strand_1[i] = 'U';
        }
    }
    std::cout << "\nRna: " << strand_1 << std::endl;
}

double DNA::idMutation(std::string strand_1)
{
    std::string strand_2 = randomStrand(6);
    std::cout << "\nRandom strand: " << strand_2 << std::endl;
    std::cout << "Inputted strand: " << strand_1 << std::endl;
    int matches = 0;
    double best_sim = 0;
    int best_index = 0;
    int pos = strand_1.length();
    for(int j = 0; j < strand_1.length() - strand_2.length(); j++)
    {
        matches = 0;
        for (int i = 0; i < strand_2.length(); i++)
        {
            if (strand_1[i + j] == strand_2[i])
            {
                matches += 1;
            }
        }
        double sim = static_cast<double>(matches) / pos;
        if(sim > best_sim)
        {
            best_sim = sim;
            best_index = j;
        }
    }

    std::cout << std::fixed << std::setprecision(3) << "Best match at position " << best_index + 1 << " With a similarity of " << best_sim << std::endl;

    for(int i = 0; i < strand_1.length(); i++)
    {
        if(i < best_index)
        {
            std::cout << "Deletion at " << i + 1 << std::endl;
        }
        else if(i >= best_index && i < best_index + strand_2.length())
        {
            if (strand_1[i] != strand_2[i - best_index])
            {
                std::cout << "Substitution at " << i + 1 << ": " << strand_1[i] << " -> " << strand_2[i - best_index] << std::endl;
            }
        }
        else
        {
            std::cout << "Deletion at " << i + 1 << std::endl;
        }
    }

    return best_sim;
}
