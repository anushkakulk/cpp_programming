/*
Anushka Kulkarni
7/13/23

represents the Critter class, a base class for types of critters.
    - virtual and static functions
*/
#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <vector>
#include <algorithm>
#include <cstdbool>
#include <cstdlib>
#include <ncurses.h>

#define GRID_SIZE = 100;
using namespace std;

class Critter
{

public:
    pair<int, int> coords;
    char type;
    int hungry;

    Critter(pair<int, int>);
    // moves critter to valid coordinates
    virtual void move(vector<Critter *> &) = 0;
    // breeds this critter
    virtual void breed(vector<Critter *> &) = 0;
    // processes the given critter on each time step
    virtual void process(vector<Critter *> &) = 0;

    // ----- COMMON CRITTER METHODS -------- //

    // adds a critter to the list of critters
    void add_critter(vector<Critter *> &, Critter *c);
    // returns true if a critter exists at the given posn
    static bool critter_exists(vector<Critter *> &, int x_pos, int y_pos);
    // removes the critter at the given pos
    void delete_critter(vector<Critter *> &, int x_pos, int y_pos);
    // change this critter's position to given posn
    void set_coord(pair<int, int>);
};

#endif // CRITTER_HPP