#include "alphaman.h"

AlphaMan::AlphaMan()
{
    Name = "AlphaMan";
}

AlphaMan::~AlphaMan()
{

}

void AlphaMan::Attack()
{

}

bool AlphaMan::isVisible() const
{

}

void AlphaMan::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

sf::Vector2i AlphaMan::get_position_on_grid()
{
    return position_on_grid;
}
