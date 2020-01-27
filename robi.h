#ifndef ROBI_H
#define ROBI_H

#include "hero.h"
#include "robicard.h"

class Robi : public Hero
{
public:
    Robi(sf::RenderWindow*);
    virtual ~Robi();
    virtual void Attack() override;
    virtual bool isVisible() const override;
    void set_position_on_grid(sf::Vector2i);
    sf::Vector2i get_position_on_grid();
    RobiCard robicard ;
private:
    sf::Vector2i position_on_grid;
};

#endif // ROBI_H
