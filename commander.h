#ifndef COMMANDER_H
#define COMMANDER_H

#include "hero.h"
#include "commandercard.h"

class Commander : public Hero
{
public:
    Commander(sf::RenderWindow*);
    virtual ~Commander();
    virtual void Attack(sf::Vector2i,Grid*,std::vector<Hero*>&) override;
    virtual bool isVisible() const override;
    void set_position_on_grid(sf::Vector2i);
    sf::Vector2i& get_position_on_grid();
    CommanderCard commandercard ;
private:
};

#endif // COMMANDER_H
