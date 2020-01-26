#ifndef COMMANDER_H
#define COMMANDER_H

#include "hero.h"

class Commander : public Hero
{
public:
    Commander();
    virtual ~Commander();
    virtual void Attack() override;
    virtual bool isVisible() const override;
    void set_position_on_grid(sf::Vector2i);
    sf::Vector2i get_position_on_grid();
private:
    sf::Vector2i position_on_grid;
};

#endif // COMMANDER_H
