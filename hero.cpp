#include "hero.h"

Hero::~Hero() {}

short int& Hero::getHealth() {}

unsigned short& Hero::getPower() {}

bool Hero::isSelected()
{
    return Selected;
}

bool Hero::getAttackPermision()
{
    return AttackPermision;
}

sf::Vector2i& Hero::get_position_on_grid() {}
