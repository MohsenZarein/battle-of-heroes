#ifndef COMMANDER_H
#define COMMANDER_H

#include "hero.h"
#include "commandercard.h"

class Commander : public Hero
{
public:
    Commander(sf::RenderWindow*);
    virtual ~Commander();
    virtual void Attack() override;
    virtual bool isVisible() const override;
    void set_position_on_grid(sf::Vector2i);
    sf::Vector2i get_position_on_grid();
    CommanderCard commandercard ;
private:
    sf::Vector2i position_on_grid;
};

#endif // COMMANDER_H
