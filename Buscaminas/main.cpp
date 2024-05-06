#include <iostream>
#include<SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Headers/Game.h"

using namespace sf;

int main() {
    Game game;
    game.start();
    RenderWindow app;
    app.create(VideoMode(game.w_width, game.w_height), "Minesweeper");

    Texture t;
    t.loadFromFile("/Users/ivanfl/Desktop/Escritorio - MB Pro de Ivan/INGENIERIA CETI/2DO SEMESTRE/PROGRAMACION ORIENTADA A OBJETOS/Segundo Parcial/SFML Proyects/Buscaminas/images/tiles.jpg");
    Sprite s(t);

    game.asign_fields(); // Asing bomb, or an ampy space
    game.count_for_bombs(); // Check for the empy spaces, how many bombs are around them

    while (app.isOpen())
    {
        if (game.exit) app.close(); // If case 4, exit the game

        Vector2i pos = Mouse::getPosition(app); // Getting muse coordenates
        int x = pos.x / game.w; // Div the x position / size of field
        int y = pos.y / game.w; // Div the y position / size of field

        Event e;
        while (app.pollEvent(e)) {
            if (e.type == Event::Closed)
                app.close();

            if (e.type == Event::MouseButtonPressed) // Id user right click
                if (e.key.code == Mouse::Left) { // If its a normal click, reveal the field
                    game.show_pressed(x,y); // Show value of the current field
                    game.get_empty_field(x,y); // Check if the field pressed is empty
                    game.empty_floodfill(game.get_empty_field(x,y) , x, y); // Check if the field is empty
                    // game.empty_floodfill(x,y);
                    if (game.get_you_loose(x,y)) std::cout << "You loose" << std::endl;


                    // std::cout << "Fila " << x << std::endl;
                    // std::cout << "Columna " << y << std::endl;
                }
                else if (game.you_loose == false && e.key.code == Mouse::Right) game.show_flag(x,y); // Show a flag in the current field
                else if (game.you_loose == true && e.key.code == Mouse::Right) { // Reset the game
                    app.close(); // Close the game window
                    game.start(); // Start new game
                    game.asign_fields(); // Asing bomb, or an ampy space
                    game.count_for_bombs(); // Check for the empy spaces, how many bombs are around them
                    game.you_loose = false; // Set variable you_loose to false
                    app.create(VideoMode(game.w_width, game.w_height), "Minesweeper"); // Crear a new window
                }
        }

        app.clear(Color::White); // Se a white color background
        for (int i = 1; i <= game.COLMS; i++) // Number of Columns in game
            for (int j = 1; j <= game.ROWS; j++) { // Number of rows in game

                if (game.sgrid[x][y] == 9) game.sgrid[i][j] = game.grid[i][j]; // If the pressed field is a bombo, show all the board (You loose)

                s.setTextureRect(IntRect(game.sgrid[i][j] * game.w, 0, game.w, game.w)); //
                s.setPosition(i * game.w, j * game.w);
                app.draw(s);
            }
        app.display();
    }
}