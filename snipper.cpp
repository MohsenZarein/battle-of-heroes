#include "snipper.h"

Snipper::Snipper(sf::RenderWindow* window) : snippercard(window)
{
    Name = "Snipper";
    this->window = window;
    card = &snippercard;
}

Snipper::~Snipper()
{

}

void Snipper::Attack()
{

}

bool Snipper::isVisible() const
{

}

void Snipper::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

sf::Vector2i Snipper::get_position_on_grid()
{
    return position_on_grid;
}
