#define WELL_WIDTH 100
#define WELL_HEIGHT 100

using namespace std;

struct simwindow_t
{
  int upper_left_x;
  int upper_left_y;
  int width;
  int height;
  char draw_char;
  char color[3];
};

typedef struct simwindow_t simwindow_t;

simwindow_t *init_GameWindow(int, int, int, int);
void undraw_Gamewindow(simwindow_t *);
void draw_Gamewindow(simwindow_t *);