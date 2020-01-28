#include "alphaman.h"

using namespace sf;

AlphaMan::AlphaMan(sf::RenderWindow* window) : alphamancard(window)
{
    Name = "AlphaMan";
    this->window = window;
    card = &alphamancard;
}

AlphaMan::~AlphaMan()
{

}

void AlphaMan::Attack(Vector2i goal , Grid* OpponentGrid , std::vector<Hero*> &OpponentHeroes)
{

}

bool AlphaMan::isVisible() const
{

}

void AlphaMan::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

sf::Vector2i& AlphaMan::get_position_on_grid()
{
    return position_on_grid;
}
