#include "kratos.h"

using namespace sf;

Kratos::Kratos(sf::RenderWindow* window) : kratoscard(window)
{
    Name = "Kratos";
    this->window = window;
    card = &kratoscard;
}

Kratos::~Kratos()
{

}

void Kratos::Attack(Vector2i goal , Grid* OpponentGrid , std::vector<Hero*> &OpponentHeroes)
{

}

bool Kratos::isVisible() const
{

}

void Kratos::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

sf::Vector2i& Kratos::get_position_on_grid()
{
    return position_on_grid;
}
