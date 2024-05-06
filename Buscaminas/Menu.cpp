#include <iostream>
#include "Headers/Menu.h"

void Menu::print_menu() {
    std::cout << std::endl << "Choose dificulty: " << std::endl;
    std::cout << "1. Easy" << std::endl;
    std::cout << "2. Medium" << std::endl;
    std::cout << "3. Hard" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Your selection (1, 2 or 3): ";
}
