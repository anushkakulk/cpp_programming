#include <cstdlib>
#include <ncurses.h>
#include "sim_window.hpp"

// taken frmo assignment 3 snake game
simwindow_t *init_GameWindow(int upper_left_x, int upper_left_y, int width, int height)
{
	simwindow_t *g;
	g = (simwindow_t *)malloc(sizeof(simwindow_t));
	g->upper_left_x = upper_left_x;
	g->upper_left_y = upper_left_y;
	g->width = width;
	g->height = height;
	g->draw_char = '*';
	return (g);
}


void draw_Gamewindow(simwindow_t *r)
{
	int row_counter, column_counter;

	// Draw Top of room
	for (row_counter = r->upper_left_x;
		 row_counter <= (r->upper_left_x + r->width);
		 row_counter++)
	{
		mvprintw(r->upper_left_y, row_counter, "%c", r->draw_char);
	}

	// Draw left side of room
	for (column_counter = r->upper_left_y;
		 column_counter <= (r->upper_left_y + r->height);
		 column_counter++)
	{
		mvprintw(column_counter, r->upper_left_x, "%c", r->draw_char);
	}

	// Draw right side of room
	for (column_counter = r->upper_left_y;
		 column_counter <= (r->upper_left_y + r->height);
		 column_counter++)
	{
		mvprintw(column_counter, (r->upper_left_x + r->width), "%c", r->draw_char);
	}

	// Draw Bottom of room
	for (row_counter = r->upper_left_x;
		 row_counter <= (r->upper_left_x + r->width);
		 row_counter++)
	{
		mvprintw(r->upper_left_y + r->height, row_counter, "%c", r->draw_char);
	}
}


void undraw_Gamewindow(simwindow_t *r)
{
	int row_counter, column_counter;

	// Undraw Top of room
	for (row_counter = r->upper_left_x;
		 row_counter <= (r->upper_left_x + r->width);
		 row_counter++)
	{
		mvprintw(r->upper_left_y, row_counter, " ");
	}

	// Undraw left side of room
	for (column_counter = r->upper_left_y;
		 column_counter <= (r->upper_left_y + r->height);
		 column_counter++)
	{
		mvprintw(column_counter, r->upper_left_x, " ");
	}

	// Undraw right side of room
	for (column_counter = r->upper_left_y;
		 column_counter <= (r->upper_left_y + r->height);
		 column_counter++)
	{
		mvprintw(column_counter, (r->upper_left_x + r->width), " ");
	}

	// Undraw Bottom of room
	for (row_counter = r->upper_left_x;
		 row_counter <= (r->upper_left_x + r->width);
		 row_counter++)
	{
		mvprintw(r->upper_left_y + r->height, row_counter, " ");
	}
}
/* room.c ends here */