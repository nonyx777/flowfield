#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Cell{
    public:
        sf::RectangleShape cell_property;
    public:
        Cell(sf::Vector2f size, sf::Vector2f position, float angle);
        int column, row;
        sf::Color state;
    
    public:
        sf::Vector2f size;
        sf::Vector2f direction;

    public:
        void render(sf::RenderTarget* target);    
};
