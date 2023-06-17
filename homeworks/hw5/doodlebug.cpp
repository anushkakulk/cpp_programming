#include "doodlebug.hpp"

DoodleBug::DoodleBug(pair<int, int> coords) : Critter(coords)
{
  type = 'X';
  this->lifespan = 0;
};

DoodleBug DoodleBug::operator++(int dummy) {
  DoodleBug temp = *this;
  this->lifespan++;
  return temp;

}
void DoodleBug::move(vector<Critter *> &critters)
{

    int min_x = this->coords.first - 1;
    int max_x = this->coords.first + 1;
    int min_y = this->coords.second - 1;
    int max_y = this->coords.second + 1;

    // list of valid moves
    vector<pair<int, int>> valid_moves;
    vector<pair<int, int>> all_moves;

    for (int i = min_x; i <= max_x; i += 1)
    {
        for (int j = min_y; j <= max_y; j += 1)
        {
            pair<int, int> posn = make_pair(i, j);            
            all_moves.push_back(posn);
        }
    }
    for (const auto& item : all_moves) {
        // if there isnt a db there, its valid
        if (CritterTypes::db != static_cast<CritterTypes>(mvinch(item.second, item.first)))
         {
         valid_moves.push_back(item);
         }
    }
  // gets the first prey it can and eats it/moves 
  bool foundPrey = false;
  for (const auto &posn : valid_moves)
  {
    if (Critter::critter_exists(critters, posn.first, posn.second))
    {
      char curr_type = ' ';
      for (Critter *c : critters)
      {
        if (c->coords.first == posn.first && c->coords.second == posn.second)
        {
            curr_type = c->type;
        }
      }
      CritterTypes possible_prey = static_cast<CritterTypes>(curr_type);
      if (possible_prey == CritterTypes::queen || possible_prey == CritterTypes::male || possible_prey == CritterTypes::worker)
      {
        Critter::delete_critter(critters, posn.first, posn.second);
        this->set_coord(posn);
        this->hungry =0;
        foundPrey = true;
        break;
      }
    }
  }

  if (!foundPrey)
  {
    this->hungry+=1;
    // avoid floating point exception lol
    if (!valid_moves.empty()) {
    pair<int, int> m = valid_moves[rand() % valid_moves.size()];
    // move if out of bounds
    if ('*' != mvinch(m.second, m.first))
    {
        this->set_coord(m);
    }
    }
  }
}

void DoodleBug::process(vector<Critter *> &critters)
{
  // dbs die if they havent eaten in 10 timesteaps
  if (this->hungry >= 10)
  {
    Critter::delete_critter(critters, this->coords.first, this->coords.second);
  }
  else
  {

    int before_x = this->coords.first;
    int before_y = this->coords.second;

    this->move(critters);
    if (before_x == this->coords.first && before_y == this->coords.second)
    {
      this->hungry += 1;
    }
    else
    {
     this->hungry = 0;
    }
  }
    this->breed(critters);
  
    (*this)++; // increase life using operator ++
}

void DoodleBug::breed(vector<Critter*>& critters)
{
    int min_x = this->coords.first - 2;
    int max_x = this->coords.first + 2;
    int min_y = this->coords.second - 2;
    int max_y = this->coords.second + 2;

    if (this->lifespan > 0 && this->lifespan % 10 == 0)
    {
        vector<pair<int, int>> valid_spawns;
        vector<pair<int, int>> all_moves;

        for (int i = min_x; i <= max_x; i += 1)
        {
            for (int j = min_y; j <= max_y; j += 1)
            {
                    pair<int, int> posn = make_pair(i, j);
                    all_moves.push_back(posn);
                
            }
        }

        for (const auto& item : all_moves)
        {
            // if there isn't a critter type there, it's valid to breed there
            if (!CritterTypeHelper::contains(mvinch(item.second, item.first)))
            {
                valid_spawns.push_back(item);
            }
        }

        // two babies
        for (int i = 0; i < 2; i++)
        {
            // no floating exceptionnnn
            if (!valid_spawns.empty())
            {
              int in = rand() % valid_spawns.size();
              if (in < valid_spawns.size()) {
                Critter* baby = new DoodleBug(valid_spawns[in]);
                critters.push_back(baby);
                valid_spawns.erase(valid_spawns.begin() + in);
            }
          }
        }
    }
}