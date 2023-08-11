#include "../../include/cell/Cell.hpp"

const sf::Vector2f left_direction = sf::Vector2f(-1.f, 0.f);
const sf::Vector2f right_direction = sf::Vector2f(1.f, 0.f);
const sf::Vector2f up_direction = sf::Vector2f(0.f, -1.f);
const sf::Vector2f down_direction = sf::Vector2f(0.f, 1.f);

//defining constructors
Cell::Cell(sf::Vector2f size, sf::Vector2f position, float angle){
    this->size = size;

    //forming the shape and related properties
    this->cell_property.setFillColor(sf::Color::Transparent);
    this->cell_property.setOutlineColor(sf::Color::White);
    this->cell_property.setOutlineThickness(0.5f);
    this->cell_property.setSize(sf::Vector2f(1.f, size.y));
    this->cell_property.setPosition(sf::Vector2f((size.x - 2)+ position.x, position.y));
    this->cell_property.setRotation(angle);

    if(angle == 0){
        this->direction = down_direction;
        this->pointing_up = false;
        this->pointing_right = false;
        this->pointing_left = false;
        this->pointing_down = true;
    }
    else if(angle == 90){
        this->direction = right_direction;
        this->pointing_up = false;
        this->pointing_down = false;
        this->pointing_left = false;
        this->pointing_right = true;
    }
    else if(angle == 180){
        this->direction = up_direction;
        this->pointing_down = false;
        this->pointing_right = false;
        this->pointing_left = false;
        this->pointing_up = true;
    }
    else{
        this->direction = left_direction;
        this->pointing_up = false;
        this->pointing_right = false;
        this->pointing_down = false;
        this->pointing_left = true;
    }
}

//defining functions
void Cell::render(sf::RenderTarget* target){
    target->draw(this->cell_property);
}