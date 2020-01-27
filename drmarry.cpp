#include "drmarry.h"


DrMarry::DrMarry()
{
    Name = "DrMarry";
}

DrMarry::~DrMarry()
{

}

void DrMarry::Attack()
{

}

bool DrMarry::isVisible() const
{

}

void DrMarry::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

sf::Vector2i DrMarry::get_position_on_grid()
{
    return position_on_grid;
}
