#include <iostream>
#include<ctime>

#include <queue>

#include "Headers/Global_settings.h"
#include "Headers/Game.h"
#include "Headers/Menu.h"
#include "Headers/Game_settings.h"

void Game::game_window(unsigned int difficulty) {
    switch (difficulty) {
        case 1:
            w_width = e_width;
            w_height = e_heigth;

            COLMS = E_COLMS;
            ROWS = E_ROWS;
            break;
        case 2:
            w_width = m_width;
            w_height = m_heigth;

            COLMS = M_COLMS;
            ROWS = M_ROWS;
            break;
        case 3:
            w_width = h_width;
            w_height = h_heigth;

            COLMS = H_COLMS;
            ROWS = H_ROWS;
            break;
        case 4:
            exit = true;
            std::cout << "See you soon!";
            break;
        default:
            break;
    }
}
void Game::asign_fields() {
    // Asing bomb, or an ampy space
    srand(time(0));

    for(int i = 1; i <= COLMS; i++)
        for (int j = 1; j <= ROWS ; j++) {
            sgrid[i][j] = 10; // Every field is gonna be cover by a block

            if (rand() % 5 == 0) grid[i][j] = 9; // If the operation is correct, asing current field a bomb
            else grid[i][j] = 0; // If not, asign an empy field

            //grid[i][j] = 0; // If not, asign an empy field
        }
}
void Game::count_for_bombs() {
    // Check for the empy spaces, how many bombs are around them
    for (int i = 1; i <= COLMS; i++)
        for (int j = 1; j <= ROWS ; j++) {
            int n = 0; // Number of bombs near by
            if (grid[i][j] == 9) continue; // It thers a bomb, dont count it
            if (grid[i + 1][j] == 9) n++; // Check Rigth Field
            if (grid[i][j + 1] == 9) n++; // Check Top Field
            if (grid[i - 1][j] == 9) n++; // Check Left Field
            if (grid[i][j - 1] == 9) n++; // Check Bottom Field

            if (grid[i + 1][j + 1] == 9) n++; // Chek Top Right Corner
            if (grid[i - 1][j - 1] == 9) n++; // Check Bottom left Corner
            if (grid[i - 1][j + 1] == 9) n++; // Check Bottom Rigth Corner
            if (grid[i + 1][j - 1] == 9) n++; // Check Top Left Corner

            grid[i][j] = n; // The result of the sum is the number that shows in the clicked field
        }
}
void Game::show_pressed(int x, int y) {
    sgrid[x][y] = grid[x][y]; // Show the field pressed in te board the value of the field
}
bool Game::get_you_loose(int x, int y) {
    if(sgrid[x][y] == 9) you_loose = true;
    return you_loose;
}
bool Game::get_empty_field(int x, int y) {
    if(sgrid[x][y] == 0) empty_field = true;
    else empty_field = false;
    return empty_field;
}
/*void Game::empty_floodfill(bool is_empty, int x, int y) {
    if (is_empty == false || x < 0 || x >= COLMS || y < 0 || y >= ROWS) {
        return; // Exit recursion if not empty or out of bounds
    }

    if (sgrid[x][y] == 9) {
        return; // Don't reveal bombs
    }

    if (sgrid[x][y] != 0) {
        show_pressed(x, y); // Reveal non-empty cells
        return; // Stop recursion for non-empty cells
    }

    std::cout << "Empty field" << std::endl;
    show_pressed(x, y); // Reveal empty cell

    for (int i = y; i <= COLMS; i++) {
        for (int j = x; j <= ROWS; j++) {
            if (grid[x + i][y + j] != 9) show_pressed(x + i, y + j);; // Check Rigth Field
            std::cout << "Theres an empty field"<< std::endl;
        }
    }
    for (int i = y; i >= 0; i--) {
        for (int j = x; j > 0; j--) {
            if (grid[x - i][y - j] != 9) show_pressed(x - i, y - j);; // Check Rigth Field
            std::cout << "Theres an empty field"<< std::endl;
        }
    }
}*/
/*void Game::empty_floodfill(bool is_empyy, int x, int y) { // Function with better rsults
    bool t_right = true, t_left = true, b_right = true, b_left = true;
    while (is_empyy == true) {
        while (t_right) {
            while (t_left) {
                while (b_right) {
                    while (b_left) {
                        for (int i = y; i <= COLMS; i++) { // check the left part for empty fields
                            for (int j = x; j >= 0; j--) {
                                if (get_empty_field(j,i) == false) b_left = false;
                                if (grid[j][i] == 9) break;
                                show_pressed(j,i);
                                if (grid[j][y] > 0 && grid[j][y] < 9) break;
                            }
                        }
                    } // While b_left
                    for (int i = y; i <= COLMS; i++) { // check the left part for empty fields
                        for (int j = x; j <= ROWS; j++) {
                            if (get_empty_field(j,i) == false) b_right = false;
                            if (grid[j][i] == 9) break;
                            show_pressed(j,i);
                            if (grid[j][y] > 0 && grid[j][y] < 9) break;
                        }
                    }
                } // While b_right
                for (int i = y; i >= 0; i--) { // check the left part for empty fields
                    for (int j = x; j <= ROWS; j++) {
                        if (get_empty_field(j,i) == false) t_left = false;
                        if (grid[j][i] == 9) break;
                        show_pressed(j,i);
                        if (grid[j][y] > 0 && grid[j][y] < 9) break;
                    }
                }
            } // While t_right
            for (int i = y; i >= 0; i--) { // check the left part for empty fields
                for (int j = x; j <= ROWS; j++) {
                    if (get_empty_field(j,i) == false) t_right = false;
                    if (grid[j][i] == 9) break;
                    show_pressed(j,i);
                    if (grid[j][y] > 0 && grid[j][y] < 9) break;
                }
            }
        } // While t_right
        is_empyy = false;
    }
}*/

void Game::empty_floodfill(bool is_empty, int x, int y) {
    if (!is_empty) return; // Exit if not empty

    if (f_visited[x][y]) return; // Exit if already vidite
    f_visited[x][y] = true; // Mark current cell as visites

    for (int dx : {-1, 0, 1}) {
        for (int dy : { -1, 0 ,1} ) {
            if (dx == 0 && dy == 0) continue;
            int newX = x + dx;
            int newY = y + dy;
            //std::cout << "(" << newX <<", " << newY << ")" << std::endl;
            if (newX > 0 && newX <= ROWS && newY > 0 && newY <= COLMS) { // If newX and newY arent bigger/smaller than grid
                show_pressed(newX, newY); // Reveal the empty cell
                if (grid[newX][newY] >= 1 && grid[newX][newY] < 9) return; // If field reveled its a number, strop
                if (get_empty_field(newX, newY)) empty_floodfill(true, newX, newY); // If (newX,nweY) are empty fields
            } else if (grid[newX][newY] == 9) return; // if (newX,newY) is a bombo, stop
        }
    }
}
void Game::show_flag(int x, int y) {
    sgrid[x][y] = 11; // Show a flag in the current field
}
void Game::start() {
    menu.print_menu();
    std::cin >> difficulty;
    //game.game_difficulty(difficulty);
    game_window(game.game_difficulty(difficulty));
}