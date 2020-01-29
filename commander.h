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
    virtual float& getHealth() override;
    virtual unsigned short int& getPower() override;
    virtual sf::Vector2i& get_position_on_grid() override;
    void set_position_on_grid(sf::Vector2i);
    CommanderCard commandercard ;
private:
};

#endif // COMMANDER_H
