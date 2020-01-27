#include "mrsghost.h"
using namespace sf;


MrsGhost::MrsGhost(sf::RenderWindow* window) : mrsghostcard(window)
{
    this->window = window;
    Name = "MrsGhost";
   // mrsghostcard = new MrsGhostCard(window);
    card = &mrsghostcard;
    //mrsghostcard = dynamic_cast<MrsGhostCard*>(card);
}

MrsGhost::~MrsGhost()
{
    //delete mrsghostcard;
}

void MrsGhost::Attack()
{

}

bool MrsGhost::isVisible() const
{
    return true;
}

void MrsGhost::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

sf::Vector2i MrsGhost::get_position_on_grid()
{
    return position_on_grid;
}
