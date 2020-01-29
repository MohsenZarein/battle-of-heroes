#include "drmarry.h"

using namespace sf;

DrMarry::DrMarry(sf::RenderWindow* window) : drmarrycard(window)
{
    Name = "DrMarry";
    this->window = window;
    health = 8;
    power = 2;
    card = &drmarrycard;
}

DrMarry::~DrMarry()
{

}

void DrMarry::Attack(Vector2i goal , Grid* OpponentGrid , Grid* myGrid, std::vector<Hero*> &OpponentHeroes)
{

}

unsigned short int& DrMarry::getHealth()
{
    return health;
}

unsigned short int& DrMarry::getPower()
{
    return power;
}


void DrMarry::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

sf::Vector2i& DrMarry::get_position_on_grid()
{
    return position_on_grid;
}
