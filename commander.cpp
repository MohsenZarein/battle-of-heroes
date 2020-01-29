#include "commander.h"

using namespace sf;

Commander::Commander(sf::RenderWindow* window) : commandercard(window)
{
    Name = "Commander";
    this->window = window;
    health = 7;
    power = 3;
    card = &commandercard;
}

Commander::~Commander()
{

}

void Commander::Attack(Vector2i goal , Grid* OpponentGrid , Grid* myGrid, std::vector<Hero*> &OpponentHeroes)
{

}

unsigned short int& Commander::getHealth()
{
    return health;
}

unsigned short int& Commander::getPower()
{
    return power;
}


void Commander::set_position_on_grid(sf::Vector2i positio_on_grid)
{
    this->position_on_grid = positio_on_grid;
}

sf::Vector2i& Commander::get_position_on_grid()
{
    return position_on_grid;
}
