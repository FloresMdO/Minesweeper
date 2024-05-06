#pragma once

#include "Menu.h"

class Game_settings {
public:
    // Variable to select game difficulty
    unsigned int user_input = 0;

    // Define Game difficulty base on user's choice
    unsigned int game_difficulty(unsigned int user_input);
};