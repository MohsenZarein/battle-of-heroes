#include "kratos.h"

Kratos::Kratos(sf::RenderWindow* window) : kratoscard(window)
{
    Name = "Kratos";
    this->window = window;
    card = &kratoscard;
}

Kratos::~Kratos()
{

}

void Kratos::Attack()
{

}

bool Kratos::isVisible() const
{

}

void Kratos::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

sf::Vector2i Kratos::get_position_on_grid()
{
    return position_on_grid;
}
