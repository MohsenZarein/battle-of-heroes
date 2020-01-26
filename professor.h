#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "hero.h"

class Professor : public Hero
{
public:
    Professor();
    virtual ~Professor();
    virtual void Attack() override;
    virtual bool isVisible() const override;
    void set_position_on_grid(sf::Vector2i);
    sf::Vector2i get_position_on_grid();
private:
    sf::Vector2i position_on_grid;
};

#endif // PROFESSOR_H
