#include "giant.h"

using namespace sf;

Giant::Giant(sf::RenderWindow* window) : giantcard(window)
{
    Name = "Giant";
    this->window = window;
    card = &giantcard;
}

Giant::~Giant()
{

}

void Giant::Attack(Vector2i goal , Grid* OpponentGrid , std::vector<Hero*> &OpponentHeroes)
{

}

bool Giant::isVisible() const
{

}

void Giant::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

sf::Vector2i& Giant::get_position_on_grid()
{
    return position_on_grid;
}
