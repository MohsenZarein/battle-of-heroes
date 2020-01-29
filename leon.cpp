#include "leon.h"

using namespace sf;

Leon::Leon(sf::RenderWindow* window) : leoncard(window)
{
    Name = "Leon";
    this->window = window;
    health = 10;
    power = 3;
    card = &leoncard;
}

Leon::~Leon()
{

}

void Leon::Attack(Vector2i goal , Grid* OpponentGrid , Grid* myGrid, std::vector<Hero*>& OpponentHeroes)
{

}

unsigned short int& Leon::getHealth()
{
    return health;
}

unsigned short int& Leon::getPower()
{
    return power;
}


void Leon::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

sf::Vector2i& Leon::get_position_on_grid()
{
    return position_on_grid;
}
