/**
 * @file main.cc
 * @author Pablo Pérez González (alu0101318318@ull.edu.es)
 * @brief Main del juego del Tetris en C++
 * @version 0.1
 * @date 2021-10-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
