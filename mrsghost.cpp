#include "mrsghost.h"

MrsGhost::MrsGhost()
{

}

MrsGhost::~MrsGhost()
{

}

void MrsGhost::Attack()
{

}

bool MrsGhost::isVisible() const
{
    return true;
}

void MrsGhost::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

sf::Vector2i MrsGhost::get_position_on_grid()
{
    return position_on_grid;
}
