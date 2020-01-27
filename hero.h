#ifndef HERO_H
#define HERO_H

#include <SFML/Graphics.hpp>
#include "card.h"
class Hero
{
public:
    virtual ~Hero();
    virtual void Attack() = 0;
    virtual bool isVisible() const = 0;
    std::string Name;
    Card * card;
protected:
    float health;
    unsigned short int power;
    bool visibility;
    sf::RenderWindow* window;
};

#endif // HERO_H
