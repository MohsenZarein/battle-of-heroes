#include "kratos.h"

using namespace sf;

Kratos::Kratos(sf::RenderWindow* window) : kratoscard(window)
{
    Name = "Kratos";
    this->window = window;
    health = 15;
    power = 3;
    card = &kratoscard;
}

Kratos::~Kratos()
{

}

void Kratos::Attack(Vector2i goal , Grid* OpponentGrid , Grid* myGrid, std::vector<Hero*> &OpponentHeroes)
{

}

unsigned short int& Kratos::getHealth()
{
    return health;
}

unsigned short int& Kratos::getPower()
{
    return power;
}


void Kratos::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

sf::Vector2i& Kratos::get_position_on_grid()
{
    return position_on_grid;
}
