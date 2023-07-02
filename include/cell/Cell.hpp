#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

const sf::Color start_color = sf::Color::Green;
const sf::Color end_color = sf::Color::Red;
const sf::Color empty_color = sf::Color::Transparent;
const sf::Color visited_color = sf::Color::Yellow;
const sf::Color path_color = sf::Color::White;
const sf::Color block_color = sf::Color(129, 97, 62, 255);

class Cell{
    public:
        sf::RectangleShape cell_property;
        bool visited = false;
        Cell* parent = NULL;
    public:
        enum Type{
            START,
            END,
            EMPTY,
            PATH,
            BLOCK
        };
    public:
        Cell();
        Cell(sf::Vector2f size, sf::Vector2f position);
        int column, row;
        sf::Color state;
        Type type;
        std::vector<Cell> neighbours;
    
    public:
        sf::Vector2f size;


    public:
        void update();
        void render(sf::RenderTarget* target);
    
    public:
        void setColor();
};
