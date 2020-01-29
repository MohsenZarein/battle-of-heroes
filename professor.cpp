#include "professor.h"

using namespace sf;

Professor::Professor(sf::RenderWindow* window) : professorcard(window)
{
    Name  = "Professor";
    this->window = window;
    health = 11;
    power = 3;
    card = &professorcard;
}

Professor::~Professor()
{

}

void Professor::Attack(Vector2i goal , Grid* OpponentGrid , Grid* myGrid, std::vector<Hero*> &OpponentHeroes)
{

}

unsigned short int& Professor::getHealth()
{
    return health;
}

unsigned short int& Professor::getPower()
{
    return power;
}


void Professor::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

sf::Vector2i& Professor::get_position_on_grid()
{
    return position_on_grid;
}
