#ifndef ANT_HPP
#define ANT_HPP
/*
Anushka Kulkarni
7/13/23

represents the Ant class, a class derived from Critters.
there are 3 types of Ants: QueenAnts, WorkerAnts, and MaleAnts.
depending on their functionality, the ants can override their parent class
*/
#include "critter.hpp"
#include "crittertypes.hpp"

class Ant : public Critter
{
public:
    Ant(pair<int, int> coords);
    // moves the given ant depending open posiitons
    void move(vector<Critter *> &critters) override;
    // does ant process (move eat breed) on step
    void process(vector<Critter *> &critters) override;
    // does nothing by default, ants cant breed
    void breed(vector<Critter *> &critters) override;
};

class QueenAnt : public Ant
{
public:
    // bool next_to_male_flag;
    int lifespan;
    int breeding_time;     // timsteps after mmating
    vector<char> children; // all of Queen's children

public:
    QueenAnt(pair<int, int>);
    // breeds this QueenAnt
    void breed(vector<Critter *> &) override;
    // returns true if QueenAnt has spawned the next gen with a queen;
    bool contains_queen(const vector<char> &) const;
    // does queen ant process(check if should die, eat, breed) on step
    void process(vector<Critter *> &) override;
    // returns true if next to male (mating)
    bool check_for_males();
    // overloaded ++ to increment time after mating/before breeeding
    friend QueenAnt operator++(QueenAnt &);
    // increases this QueenAnt lifespan
    QueenAnt operator++(int q);
};

class WorkerAnt : public Ant
{
public:
    WorkerAnt(pair<int, int> coords);
};

class MaleAnt : public Ant
{
public:
    MaleAnt(pair<int, int> coords);
};

#endif // ANT_HPP