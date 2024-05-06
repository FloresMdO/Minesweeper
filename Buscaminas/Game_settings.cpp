#include <iostream>
#include "Headers/Menu.h"
#include "Headers/Game_settings.h"

unsigned int Game_settings::game_difficulty(unsigned int user_input) {
    do {
        if (user_input == 0 || user_input > 4) {
            std::cout << "Difficulty Error! Please choose a number from 1 to 3" << std::endl;
            std::cout << "Your selection (1, 2 or 3): "; std::cin >> user_input;
        }
    } while (user_input == 0 || user_input > 4);
    return user_input;
}
