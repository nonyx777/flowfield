#include "../../include/cell/Cell.hpp"

//defining constructors
Cell::Cell(){
    //...
}

Cell::Cell(sf::Vector2f size, sf::Vector2f position){
    this->size = size;

    //forming the shape and related properties
    this->cell_property.setFillColor(sf::Color::Transparent);
    this->cell_property.setOutlineColor(sf::Color::White);
    this->cell_property.setOutlineThickness(0.5f);
    this->cell_property.setSize(sf::Vector2f(1.f, size.y));
    this->cell_property.setPosition(sf::Vector2f((size.x - 2)+ position.x, position.y));
    this->cell_property.setRotation(0);

    if(this->cell_property.getRotation() == 0)
        this->direction = sf::Vector2f(0.f, 1.f);
    else if(this->cell_property.getRotation() == 90)
        this->direction = sf::Vector2f(1.f, 0.f);
    else if(this->cell_property.getRotation() == 180)
        this->direction = sf::Vector2f(0.f, -1.f);
    else
        this->direction = sf::Vector2f(-1, 0.f);
}

//defining functions
void Cell::update(){
    //...
}
void Cell::render(sf::RenderTarget* target){
    target->draw(this->cell_property);
}