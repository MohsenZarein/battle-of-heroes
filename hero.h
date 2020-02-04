#ifndef HERO_H
#define HERO_H

#include <SFML/Graphics.hpp>
#include "card.h"
#include "grid.h"

class Hero
{
public:
    virtual ~Hero();
    virtual void Attack(sf::Vector2i,Grid*,Grid*,std::vector<Hero*>&) = 0;
    virtual sf::Vector2i& get_position_on_grid() ;
    virtual short int& getHealth();
    virtual unsigned short int& getPower();
    virtual bool isSelected();
    virtual bool getAttackPermision();
    bool Selected;
    bool AttackPermision;
    std::string Name;
    Card * card;
protected:
    short int health;
    unsigned short int power;
    sf::Vector2i position_on_grid;
    sf::RenderWindow* window;
};

#endif // HERO_H
