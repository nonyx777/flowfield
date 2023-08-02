#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "../cell/Cell.hpp"
#include <math.h>
#include "../../src/Entities/Agent.cpp"
#include <random>
#include <ctime>
#include <chrono>

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

        //mouse position
        sf::Vector2i mouse_position;
        sf::Vector2f mouse_position_view;

        //container for agents
        std::vector<Agent> agents;
        //agent related variables
        float min_x, max_x, min_y, max_y;
        
    private:
        //grid related variabless
        int size;
        int row;
        int column;
        std::vector<std::vector<Cell>> grid_vector;
        //cell type represented by an integer
        int cell_type;

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

        //Accessors
        const bool running() const;
};