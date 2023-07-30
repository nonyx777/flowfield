#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include "../../include/cell/Cell.hpp"

class Agent{
    private:
        sf::Vector2f velocity, acceleration;

    public:
        sf::CircleShape agent_property;
        //constructor
        Agent(){
            this->agent_property.setFillColor(sf::Color::White);
            this->agent_property.setRadius(10.f);
            this->agent_property.setOrigin(10.f, 10.f);
            this->agent_property.setPosition(10.f, 10.f);
        };

        //main ball functions
        void update(std::vector<std::vector<Cell>> &grid, int &size){
            int x = floor(this->agent_property.getPosition().x/size);
            int y = floor(this->agent_property.getPosition().y/size);

            this->agent_property.move(grid[y][x].direction * 2.f); 
        }
        void render(sf::RenderTarget* target){
            target->draw(this->agent_property);
        }

        //accessors and mutators
        sf::Vector2f getVelocity(){
            return this->velocity;
        }
        void setVelocity(sf::Vector2f vector){
            this->velocity = velocity;
        }
};