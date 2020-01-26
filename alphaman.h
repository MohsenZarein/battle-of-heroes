#ifndef ALPHAMAN_H
#define ALPHAMAN_H

#include "hero.h"

class AlphaMan : public Hero
{
public:
    AlphaMan();
    virtual ~AlphaMan();
    virtual void Attack() override;
    virtual bool isVisible() const override;
    void set_position_on_grid(sf::Vector2i);
    sf::Vector2i get_position_on_grid();
private:
    sf::Vector2i position_on_grid;
};

#endif // ALPHAMAN_H
