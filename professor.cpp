#include "professor.h"

Professor::Professor()
{
    Name  = "Professor";
}

Professor::~Professor()
{

}

void Professor::Attack()
{

}

bool Professor::isVisible() const
{

}

void Professor::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

sf::Vector2i Professor::get_position_on_grid()
{
    return position_on_grid;
}
