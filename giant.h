#ifndef GIANT_H
#define GIANT_H

#include "hero.h"
#include "giantcard.h"

class Giant : public Hero
{
public:
    Giant(sf::RenderWindow*);
    virtual ~Giant();
    virtual void Attack(sf::Vector2i,Grid*,Grid*,std::vector<Hero*>&) override;
    virtual unsigned short int& getHealth() override;
    virtual unsigned short int& getPower() override;
    virtual sf::Vector2i& get_position_on_grid() override;
    void set_position_on_grid(sf::Vector2i);
    GiantCard giantcard ;
private:
};

#endif // GIANT_H
