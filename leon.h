#ifndef LEON_H
#define LEON_H

#include "hero.h"
#include "leoncard.h"

class Leon : public Hero
{
public:
    Leon(sf::RenderWindow*);
    virtual ~Leon();
    virtual void Attack(sf::Vector2i,Grid*,Grid*,std::vector<Hero*>&) override;
    virtual short int& getHealth() override;
    virtual unsigned short int& getPower() override;
    virtual sf::Vector2i& get_position_on_grid() override;
    void set_position_on_grid(sf::Vector2i);
    LeonCard leoncard ;
private:
};

#endif // LEON_H
