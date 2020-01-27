#ifndef LEON_H
#define LEON_H

#include "hero.h"
#include "leoncard.h"

class Leon : public Hero
{
public:
    Leon(sf::RenderWindow*);
    virtual ~Leon();
    virtual void Attack() override;
    virtual bool isVisible() const override;
    void set_position_on_grid(sf::Vector2i);
    sf::Vector2i get_position_on_grid();
    LeonCard leoncard ;
private:
    sf::Vector2i position_on_grid;
};

#endif // LEON_H
