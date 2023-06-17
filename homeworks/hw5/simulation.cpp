#include <ncurses.h>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define DB 1
#define Q 2
#define M 3
#define W 4

#include "simulation.hpp"

static int x_offset;
static int y_offset;

using namespace std;
void generate_points(int *crit_x, int *crit_y, int height, int width, int x_offset, int y_offset)
{

    *crit_x = rand() % width + x_offset;
    *crit_y = rand() % height + y_offset;
}

int get_top_left_X(simwindow_t *window)
{
    return window->upper_left_x;
}

int get_top_left_Y(simwindow_t *window)
{
    return window->upper_left_y;
}

// adds critters to list of critters on board at random posns
void add_critters(int num_critters, char type, vector<Critter *> &curr_critters, int &critter_xpos, int &critter_ypos, int width, int height, int x_offset, int y_offset)
{
    for (int i = 0; i < num_critters; i++)
    {
        while (Critter::critter_exists(curr_critters, critter_xpos, critter_ypos))
        {
            generate_points(&critter_xpos, &critter_ypos, width, height, x_offset, y_offset);
        }

        Critter *new_critter = nullptr;

        switch (type)
        {
        case 'X':
            new_critter = new DoodleBug(pair<int, int>(critter_xpos, critter_ypos));
            curr_critters.insert(curr_critters.begin(), new_critter);
            break;
        case 'Q':
            new_critter = new QueenAnt(pair<int, int>(critter_xpos, critter_ypos));
            curr_critters.push_back(new_critter);
            break;
        case 'o':
            new_critter = new MaleAnt(pair<int, int>(critter_xpos, critter_ypos));
            curr_critters.push_back(new_critter);
            break;
        case 'w':
            new_critter = new WorkerAnt(pair<int, int>(critter_xpos, critter_ypos));
            curr_critters.push_back(new_critter);
            break;
        }
    }

    generate_points(&critter_xpos, &critter_ypos, width, height, x_offset, y_offset);
}

void simulation(int NUM_DOODLEBUGS, int NUM_QUEENS, int NUM_MALE, int NUM_WORKERS)
{

    enum State state = INIT;         // Set the initial state
    static int x_max, y_max;         // Max screen size variables
    simwindow_t *window;             // Name of the board
    vector<Critter *> curr_critters; // list of all critters
    
    const int height = 100;
    const int width = 100;
    char ch;

    int topleft_x;
    int topleft_y;
    srand(static_cast<unsigned>(std::time(nullptr)));
    struct timespec timeret;
    timeret.tv_sec = 0;
    timeret.tv_nsec = 999999999 / 4;

    // make temp critter vector to avoid iterating thorugh the vector we are modifying !!
    vector<Critter *> temp;
    while (state != EXIT)
    {
        switch (state)
        {
        case INIT:
            initscr();
            start_color();
            nodelay(stdscr, TRUE); // Dont wait for char
            noecho();              // Don't echo input chars
            getmaxyx(stdscr, y_max, x_max);
            keypad(stdscr, TRUE); // making keys work
            curs_set(0);          // hide cursor
            timeout(100);

            // Setting height and width of the board
            x_offset = (x_max / 2) - (width / 2);
            y_offset = (y_max / 2) - (height / 2);

            // Init board
            window = init_GameWindow(x_offset, y_offset, width, height);

            draw_Gamewindow(window);

            int critter_xpos, critter_ypos;
            // pair<int, int> critter_posn;

            int NUM_QUEENS_TOTAL;
            int NUM_MALES_TOTAL;
            int NUM_ANTS_TOTAL;
            int NUM_DB_TOTAL;

        
            // creates all the critter points (copied from the snake game food generation)
            // add critters insert doodlebugs at the front while emplacing the rest in the back to ensure
            // doodlebugs get processed first
            add_critters(NUM_DOODLEBUGS, 'X', curr_critters, critter_xpos, critter_ypos, width, height, x_offset, y_offset);
            add_critters(NUM_QUEENS, 'Q', curr_critters, critter_xpos, critter_ypos, width, height, x_offset, y_offset);
            add_critters(NUM_MALE, 'o', curr_critters, critter_xpos, critter_ypos, width, height, x_offset, y_offset);
            add_critters(NUM_WORKERS, 'w', curr_critters, critter_xpos, critter_ypos, width, height, x_offset, y_offset);

            init_pair(DB, COLOR_WHITE, COLOR_BLACK);
            init_pair(Q, COLOR_MAGENTA, COLOR_BLACK);
            init_pair(M, COLOR_RED, COLOR_BLACK);
            init_pair(W, COLOR_CYAN, COLOR_BLACK);

            state = RUNNING;
            break;

        case RUNNING:
            ch = getch();
            switch (ch)
            {
            case 'q':
            case 'Q':
                state = EXIT;
                break;
            case 'p':
            case 'P':
                timeout(-1);
                ch = getch();
                while (ch != 'p' && ch != 'P')
                {
                    ;
                }
                timeout(100);
                break;
            }

            NUM_ANTS_TOTAL = 0;
            NUM_QUEENS_TOTAL = 0;
            NUM_MALES_TOTAL = 0;
            NUM_DB_TOTAL = 0;

            topleft_x = get_top_left_X(window);
            topleft_y = get_top_left_Y(window);

            // set temp to curr, process temp on each time step, then set curr to the changed temp
            // AVOIDS BAD ITERATING :))))
            temp = curr_critters;
            for (auto c : curr_critters)
            {
                // curr_critters always has doodlebugs to the front of the list to ensure they
                // get processed first
                c->process(temp);
                // inc the number of ant types to check for cyclicity
                if (c->type == 'Q')
                {
                    NUM_ANTS_TOTAL += 1;
                    NUM_QUEENS_TOTAL += 1;
                }
                else if (c->type == 'o')
                {
                    NUM_ANTS_TOTAL += 1;
                    NUM_MALES_TOTAL += 1;
                }
                else if (c->type == 'w')
                {
                    NUM_ANTS_TOTAL += 1;
                }
                else if (c->type == 'X')
                {
                    NUM_DB_TOTAL += 1;
                }
                
            }
            curr_critters = temp;
            
            clear();
            mvprintw(3, 4, "# QUEENS: %i", NUM_QUEENS_TOTAL);
            mvprintw(4, 4, "# MALES: %i", NUM_MALES_TOTAL);
            mvprintw(5, 4, "# ANTS: %i", NUM_ANTS_TOTAL);
            mvprintw(6, 4, "# DB: %i", NUM_DB_TOTAL);

            start_color();
            // render the now current critters
            for (auto c : curr_critters)
            {
                if (c->type == 'X')
                {
                    attron(COLOR_PAIR(DB));
                }
                else if (c->type == 'Q')
                {
                    attron(COLOR_PAIR(Q));
                }
                else if (c->type == 'o')
                {
                    attron(COLOR_PAIR(M));
                }
                else if (c->type == 'w')
                {
                    attron(COLOR_PAIR(W));
                }
                mvprintw(c->coords.second, c->coords.first, "%c", c->type);
                attroff(COLOR_PAIR(DB));
                attroff(COLOR_PAIR(Q));
                attroff(COLOR_PAIR(M));
                attroff(COLOR_PAIR(W));
            }

            draw_Gamewindow(window);
            // if one species is gona completely
            // or if no queens (can't breed more ants)
            // or if no males (can't breed more ants)
            if (NUM_ANTS_TOTAL <= 0 || NUM_DB_TOTAL <= 0 || NUM_QUEENS_TOTAL <= 0 || NUM_MALES_TOTAL <= 0 ) 
            {
                state = CYCLIC;
                break;
            }

            break;
        // closes sim if species dies and returns to terminal
        case CYCLIC:
            clear();
            refresh();
            undraw_Gamewindow(window);
            endwin();
            initscr();
            noecho();
            getmaxyx(stdscr, y_max, x_max);
            mvprintw(2, 20, "Simulation Over!");
            mvprintw(4, 20, "Press [q]/[Q] to exit to terminal");
            int user_exit = getch();
            if (user_exit == 'q' || user_exit == 'Q')
            {
                state = EXIT;
            }
            break;
        }
        refresh();
        nanosleep(&timeret, NULL);
    }
    clear();
    refresh();
    endwin();
}