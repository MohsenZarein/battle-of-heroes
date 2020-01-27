#include "commander.h"

Commander::Commander(sf::RenderWindow* window) : commandercard(window)
{
    Name = "Commander";
    this->window = window;
    card = &commandercard;
}

Commander::~Commander()
{

}

void Commander::Attack()
{

}

bool Commander::isVisible() const
{

}

void Commander::set_position_on_grid(sf::Vector2i positio_on_grid)
{
    this->position_on_grid = positio_on_grid;
}

sf::Vector2i Commander::get_position_on_grid()
{
    return position_on_grid;
}
