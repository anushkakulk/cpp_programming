#include <vector>
#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include "critter.hpp"

Critter::Critter(pair<int, int> coords)
{
    this->coords = coords;
    this->hungry = 0;
    this->type = 'X';
}

// adapted from snake game
void Critter::add_critter(vector<Critter *> &critters, Critter *c)
{
    // ensures doodlebugs are placed at the front of the list of critters to be
    // processed first
    if (c->type == 'X')
    {
        critters.insert(critters.begin(), c);
    }
    else
    {
        critters.push_back(c);
    }

    //cout << c << endl;
}

// adapted from snake game
bool Critter::critter_exists(vector<Critter *> &critters, int x_pos, int y_pos)
{
    for (Critter *c : critters)
    {
        if (c->coords.first == x_pos && c->coords.second == y_pos)
        {
            return true;
        }
    }
    return false;
}


void Critter::delete_critter(vector<Critter *> &critters, int x_pos, int y_pos)
{
    // for (auto c : critters) {
    //     if (c->coords == pair<int, int>(x_pos,y_pos)) {
    //         cout << c << endl;
    //     }
    // }
    critters.erase(std::remove_if(critters.begin(), critters.end(), 
        [x_pos, y_pos](Critter *critter){return critter->coords.first == x_pos && 
        critter->coords.second == y_pos;}),
        critters.end());
}

void Critter::set_coord(pair<int, int> new_coord) { this->coords = new_coord; }