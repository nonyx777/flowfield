#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include "../../include/cell/Cell.hpp"
#include "../../include/utility/Utility.hpp"

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

            sf::Vector2f desired =  (this->agent_property.getPosition() + 
            grid[y][x].direction * 10.f) - this->agent_property.getPosition();

            desired = Utility::_unitVector(desired);
            desired *= 5.f;

            sf::Vector2f steer = desired - this->velocity;

            //integration
            this->acceleration = steer * 0.05f;
            this->velocity += this->acceleration;
            this->agent_property.move(this->velocity * 0.5f);

            this->acceleration = sf::Vector2f(0.f, 0.f);
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