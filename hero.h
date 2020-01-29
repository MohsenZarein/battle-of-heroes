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
    virtual sf::Vector2i& get_position_on_grid() ;
    virtual float& getHealth();
    virtual unsigned short int& getPower();
    std::string Name;
    Card * card;
protected:
    float health;
    unsigned short int power;
    sf::Vector2i position_on_grid;
    sf::RenderWindow* window;
};

#endif // HERO_H
