#include "robi.h"
#include <iostream>

Robi::Robi()
{
    Name = "Robi";
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
