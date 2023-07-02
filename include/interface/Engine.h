#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "../cell/Cell.hpp"
#include "../dijkstra/Dijkstra.hpp"
#include <math.h>

using namespace std;

class Engine{
    private:
        //initializer functions
        void initVariables();
        void initWindow();

        //window variables
        sf::RenderWindow* window;
        sf::VideoMode video_mode;
        sf::Event event;

        //instantiating objects
        Dijkstra dijkstra;

        //mouse position
        sf::Vector2i mouse_position;
        sf::Vector2f mouse_position_view;
        
    private:
        //grid related variabless
        int size;
        int row;
        int column;
        std::vector<std::vector<Cell>> grid_vector;
        //cell type represented by an integer
        int cell_type;

        //start and end cell
        Cell startCell, endCell;

        //to track the prev cell...to revert it's color
        int prev_row;
        int prev_column;

        //text related variables
        sf::Font font;
        sf::Text text;

        //selected cells container
        sf::Vector2u selected_cell;

    public:
        //constructor and destructor
        Engine();
        ~Engine();

        //window functions
        void pollEvent();
        void update();
        void render();

        //custom functions
        void configureGridLayout(int column, int row);
        void pointLocation(sf::Vector2f &mouse_position);
        void setText(std::string particle_text);

        //Accessors
        const bool running() const;
};