#include "giant.h"

Giant::Giant()
{
    Name = "Giant";
}

Giant::~Giant()
{

}

void Giant::Attack()
{

}

bool Giant::isVisible() const
{

}

void Giant::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

sf::Vector2i Giant::get_position_on_grid()
{
    return position_on_grid;
}
