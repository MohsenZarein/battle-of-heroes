#include "robi.h"

using namespace sf;

Robi::Robi(sf::RenderWindow* window) : robicard(window)
{
    Name = "Robi";
    this->window = window;
    health = 12;
    power = 2;
    card = &robicard;
}

Robi::~Robi()
{

}

void Robi::Attack(Vector2i goal , Grid* OpponentGrid , Grid* myGrid, std::vector<Hero*> &OpponentHeroes)
{

}

unsigned short int& Robi::getHealth()
{
    return health;
}

unsigned short int& Robi::getPower()
{
    return power;
}


void Robi::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

sf::Vector2i& Robi::get_position_on_grid()
{
    return position_on_grid;
}
