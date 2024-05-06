#pragma once

#include "Menu.h"
#include "Game_settings.h"

class Game {
public:
    Menu menu;
    Game_settings game;

    int w = 32; // The size of each field is set to 32 px
    int grid[12][12]; // Single field
    int sgrid[12][12]; // For showing the grid (Board)
    bool f_visited[12][12]; // Empty fields visited

    // In game windows size
    unsigned int w_height = 0;
    unsigned int w_width = 0;
    // In game grid
    unsigned int COLMS = 0;
    unsigned int ROWS = 0;

    unsigned int empty_x = 0;
    unsigned int empty_y = 0;

    unsigned int difficulty = 0;
    bool empty_field = false;
    bool you_loose = false;
    bool exit = false;

    void game_window(unsigned int difficulty);
    void asign_fields();
    void count_for_bombs();
    void show_pressed(int x, int y);
    bool get_empty_field(int x, int y);
    void empty_floodfill(bool is_empty, int x, int y); // Function with better results
    bool get_you_loose(int x, int y);
    void show_flag(int x, int y);
    void start();
};

