#include "giant.h"

Giant::Giant(sf::RenderWindow* window) : giantcard(window)
{
    Name = "Giant";
    this->window = window;
    card = &giantcard;
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
