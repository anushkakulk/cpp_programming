#include "ants.hpp"

using namespace std;
Ant::Ant(pair<int, int> coords) : Critter(coords) { type = 'A'; };

// moves this ant to an empty place in the 8 adjacenct cells
void Ant::move(vector<Critter *> &critters)
{

    int min_x = this->coords.first - 1;
    int max_x = this->coords.first + 1;
    int min_y = this->coords.second - 1;
    int max_y = this->coords.second + 1;

    // list of valid coords
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
    for (const auto &item : all_moves)
    {
        // if there isnt have a critter type there, its valid
        if (!CritterTypeHelper::contains(mvinch(item.second, item.first)))
        {
            valid_moves.push_back(item);
        }
    }

    // no floating exceptionnnn
    if (!valid_moves.empty()) {
    // pick a random valid move
    pair<int, int> m = valid_moves[rand() % valid_moves.size()];
    // move if not out of bounds
    if ('*' != mvinch(m.second, m.first))
    {
        this->set_coord(m);
    }
    }
};
// check if ant should die, otherwise move
void Ant::process(vector<Critter *> &critters)
{
    // starved, so remove
    if (this->hungry > 5)
    {
        Critter::delete_critter(critters, this->coords.first, this->coords.second);
    }
    else
    {
        // move the critter, and if its position didnt change, then it didnt eat
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
}

void Ant::breed(vector<Critter *> &critters)
{
    // by default ants cant breed
}

// ---- QUEEN ---- //

QueenAnt::QueenAnt(pair<int, int> coords) : Ant(coords)
{
    type = 'Q';
    breeding_time = 0;
    lifespan = 0;
    vector<char> children;
};
// overloaded ++ to increment timesteps gone since breeding
QueenAnt operator++(QueenAnt &q)
{
    ++(q.breeding_time);
    return q;
}
// overloaded ++ to increment lifespan
QueenAnt QueenAnt::operator++(int dummy)
{
    QueenAnt temp = *this;
    this->lifespan++;
    return temp;
}

void QueenAnt::process(vector<Critter *> &critters)
{
    // queen ants die if they havent bred in 60 timesteps
    if (this->lifespan > 60 && this->breeding_time == 0)
    {
        Critter::delete_critter(critters, this->coords.first, this->coords.second);
    }
    else
    {

        int before_x = this->coords.first;
        int before_y = this->coords.second;

        // only moves if queen has produced the next gen or if its been 15 secs since breeding
        if (this->contains_queen(this->children) || this->breeding_time > 15)
        {
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

        if (this->breeding_time != 0)
        {
            this->hungry += 1;
            ++(*this);
        }
    }
    (*this)++;
}

// checks to see if ants (method is used passing in queen's children) conatins a queen
bool QueenAnt::contains_queen(const vector<char> &ants) const
{
    for (char c : ants)
    {
        if (static_cast<CritterTypes>(c) == CritterTypes::queen)
        {
            return true;
        }
    }
    return false;
}

// if the adjacent type is a male, queen can mate
bool QueenAnt::check_for_males()
{
    int min_x = this->coords.first - 1;
    int max_x = this->coords.first + 1;
    int min_y = this->coords.second - 1;
    int max_y = this->coords.second + 1;

    for (int i = min_x; i <= max_x; i += 1)
    {
        for (int j = min_y; j <= max_y; j += 1)
        {
            if (CritterTypes::male == static_cast<CritterTypes>(mvinch(j, i)))
            {

                return true;
            }
        }
    }
    return false;
}

void QueenAnt::breed(vector<Critter *> &critters)
{
    bool mated;
    double worker_prob = 0.6;
    double male_prob = 0.1;
    double queen_prob = 0.005;

    int min_x = this->coords.first - 2;
    int max_x = this->coords.first + 2;
    int min_y = this->coords.second - 2;
    int max_y = this->coords.second + 2;

    // if next to a male, mated flag is true
    if (check_for_males())
    {
        ++(*this);
    }

    srand(time(0));
    double random_val = static_cast<double>(std::rand()) / RAND_MAX;
    // spawn children 30 secs after
    if (this->breeding_time >= 30)
    {
        int num_children = 0;
        // 16 spots around
        for (int i = min_x; i <= max_x; i += 1)
        {
            for (int j = min_y; j <= max_y; j += 1)
            {
                pair<int, int> position(i, j);
        
                if (!(CritterTypeHelper::contains(mvinch(position.second, position.first))))
                {
                    // make 10 children w types determined by probabilites
                    if (num_children < 10)
                    {
                        double random_val = static_cast<double>(std::rand()) / RAND_MAX;
                        if (random_val < queen_prob)
                        {
                            this->children.push_back('Q');
                            Critter::add_critter(critters, new QueenAnt(position));
                        }
                        else if (random_val < queen_prob + male_prob)
                        {
                            this->children.push_back('o');
                            Critter::add_critter(critters, new MaleAnt(position));
                        }
                        else if (random_val < queen_prob + male_prob + worker_prob)
                        {
                            this->children.push_back('w');
                            Critter::add_critter(critters, new WorkerAnt(position));
                        }
                        else
                        {
                            this->children.push_back('w');
                            Critter::add_critter(critters, new WorkerAnt(position));
                        }
                        num_children += 1;
                    }
                }
            }
        }
        this->hungry = 0;
        this->breeding_time = 0;
    }
}

// ---- WORKER ANT ---- //

WorkerAnt::WorkerAnt(pair<int, int> coords) : Ant(coords)
{
    type = 'w';
};

// ---- MALE ANT ---- //

MaleAnt::MaleAnt(pair<int, int> coords) : Ant(coords)
{
    type = 'o';
};