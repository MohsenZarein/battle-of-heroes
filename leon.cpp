#include "leon.h"

Leon::Leon(sf::RenderWindow* window) : leoncard(window)
{
    Name = "Leon";
    this->window = window;
    card = &leoncard;
}

Leon::~Leon()
{

}

void Leon::Attack()
{

}

bool Leon::isVisible() const
{

}

void Leon::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

sf::Vector2i Leon::get_position_on_grid()
{
    return position_on_grid;
}
