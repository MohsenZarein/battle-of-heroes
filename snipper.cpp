#include "snipper.h"

using namespace sf;

Snipper::Snipper(sf::RenderWindow* window) : snippercard(window)
{
    Name = "Snipper";
    this->window = window;
    health = 9;
    power = 4;
    card = &snippercard;
}

Snipper::~Snipper()
{

}

void Snipper::Attack(Vector2i goal , Grid* OpponentGrid , Grid* myGrid,  std::vector<Hero*> &OpponentHeroes)
{

}

unsigned short int& Snipper::getHealth()
{
    return health;
}

unsigned short int& Snipper::getPower()
{
    return power;
}

void Snipper::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

sf::Vector2i& Snipper::get_position_on_grid()
{
    return position_on_grid;
}
