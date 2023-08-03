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
            this->agent_property.setRadius(1.f);
            this->agent_property.setOrigin(10.f, 10.f);
            this->agent_property.setPosition(600.f/2.f, 600.f/2.f);
        };

        //main ball functions
        void update(std::vector<std::vector<Cell>> &grid, int &size){
            int y = floor(this->agent_property.getPosition().y/size);
            int x = floor(this->agent_property.getPosition().x/size);

            this->teleport(grid, size, y, x);
            this->steer(grid, size, y, x);
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

        //custom functions
        void steer(std::vector<std::vector<Cell>> &grid, int &size, int &y, int &x){
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
        void teleport(std::vector<std::vector<Cell>> &grid, int &size, int &y, int &x){
            switch(y){
                case 1:
                    this->agent_property.setPosition(this->agent_property.getPosition().x, float(28.f * size));
                    break;
                case 29:
                    this->agent_property.setPosition(sf::Vector2f(this->agent_property.getPosition().x, float(2.f * size)));
                    break;
            }

            switch(x){
                case 1:
                    this->agent_property.setPosition(float(28.f * size), this->agent_property.getPosition().y);
                    break;
                case 29:
                    this->agent_property.setPosition(sf::Vector2f(float(2.f * size), this->agent_property.getPosition().y));
                    break;
            }
        }
};
