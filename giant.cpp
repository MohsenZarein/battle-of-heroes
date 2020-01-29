#include "giant.h"

using namespace sf;

Giant::Giant(sf::RenderWindow* window) : giantcard(window)
{
    Name = "Giant";
    this->window = window;
    health = 20;
    power = 4;
    card = &giantcard;
}

Giant::~Giant()
{

}

void Giant::Attack(Vector2i goal , Grid* OpponentGrid , Grid* myGrid, std::vector<Hero*> &OpponentHeroes)
{

}

unsigned short int& Giant::getHealth()
{
    return health;
}

unsigned short int& Giant::getPower()
{
    return power;
}


void Giant::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

sf::Vector2i& Giant::get_position_on_grid()
{
    return position_on_grid;
}
