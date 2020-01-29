#include "alphaman.h"

using namespace sf;

AlphaMan::AlphaMan(sf::RenderWindow* window) : alphamancard(window)
{
    Name = "AlphaMan";
    this->window = window;
    health = 13;
    power = 2;
    card = &alphamancard;
}

AlphaMan::~AlphaMan()
{

}

void AlphaMan::Attack(Vector2i goal , Grid* OpponentGrid , Grid* myGrid, std::vector<Hero*> &OpponentHeroes)
{

}

unsigned short int& AlphaMan::getHealth()
{
    return health;
}

unsigned short int& AlphaMan::getPower()
{
    return power;
}


void AlphaMan::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

sf::Vector2i& AlphaMan::get_position_on_grid()
{
    return position_on_grid;
}
