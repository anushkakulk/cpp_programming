/*
Anushka Kulkarni
7/13/23

represents the DoodleBug class, derived from Critter
*/

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "critter.hpp"
#include "crittertypes.hpp"

class DoodleBug : public Critter {
public:
  int lifespan;

public:
  DoodleBug(pair<int, int> coords);

  // moves DoodleBug based on the closest ant in its adjacency
   void move(vector<Critter *> &critters) override;
  // does doodlebug process(check if starved, eat, breed) on step
   void process(vector<Critter*>& critters) override;
  // breeds 2 DoodleBugs from this doodlebug
   void breed(vector<Critter *> &critters) override;
  // increases this doodlebugs lifespan
  DoodleBug operator++(int q);
};

#endif // DOODLEBUG_HPP