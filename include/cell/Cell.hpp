#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Cell{
    public:
        sf::RectangleShape cell_property;
    public:
        Cell();
        Cell(sf::Vector2f size, sf::Vector2f position);
        int column, row;
        sf::Color state;
    
    public:
        sf::Vector2f size;
        sf::Vector2f direction;

    public:
        void update();
        void render(sf::RenderTarget* target);    
};
