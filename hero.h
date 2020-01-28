#ifndef HERO_H
#define HERO_H

#include <SFML/Graphics.hpp>
#include "card.h"
#include "grid.h"

class Hero
{
public:
    virtual ~Hero();
    virtual void Attack(sf::Vector2i,Grid*,std::vector<Hero*>&) = 0;
    virtual bool isVisible() const = 0;
    virtual sf::Vector2i& get_position_on_grid() = 0;
    std::string Name;
    Card * card;
protected:
    float health;
    unsigned short int power;
    bool visibility;
    sf::Vector2i position_on_grid;
    sf::RenderWindow* window;
};

#endif // HERO_H
