#include "robi.h"

using namespace sf;

Robi::Robi(sf::RenderWindow* window) : robicard(window)
{
    Name = "Robi";
    this->window = window;
    card = &robicard;
}

Robi::~Robi()
{

}

void Robi::Attack(Vector2i goal , Grid* OpponentGrid , std::vector<Hero*> &OpponentHeroes)
{

}

float& Robi::getHealth()
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
