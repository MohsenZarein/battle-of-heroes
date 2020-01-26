#ifndef HERO_H
#define HERO_H

#include <SFML/Graphics.hpp>

class Hero
{
public:
    virtual ~Hero();
    virtual void Attack() = 0;
    virtual bool isVisible() const = 0;
protected:
    float health;
    unsigned short int power;
    bool visibility;
};

#endif // HERO_H
