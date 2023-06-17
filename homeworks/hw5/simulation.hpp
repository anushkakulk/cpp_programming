#include "sim_window.hpp"
#include "critter.hpp"
#include "crittertypes.hpp"
#include "ants.hpp"
#include "doodlebug.hpp"
// takes in user input for number of bugs
void simulation(int NUM_DOODLEBUGS, int NUM_QUEENS, int NUM_MALE, int NUM_WORKERS);

void generate_points(int *food_x, int *food_y, int height, int width, int x_offset, int y_offset);

// adds critters to the vector of all critters at initialization with critters getting random points created by generate points
// methods
void add_critters(int num_critters, char type, std::vector<Critter*>& curr_critters,
                              int &critter_xpos, int &critter_ypos, int width, int height, int x_offset, int y_offset);

int get_top_left_X(simwindow_t*);
int get_top_left_Y(simwindow_t*);
enum State
{
    INIT,
    RUNNING,
    CYCLIC,
    EXIT
};