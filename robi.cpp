#include "robi.h"
#include <iostream>

Robi::Robi(sf::RenderWindow* window) : robicard(window)
{
    Name = "Robi";
    this->window = window;
    card = &robicard;
}

Robi::~Robi()
{

}

void Robi::Attack()
{

}

bool Robi::isVisible() const
{

}

void Robi::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

sf::Vector2i Robi::get_position_on_grid()
{
    return position_on_grid;
}
