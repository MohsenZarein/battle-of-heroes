#ifndef DRMARRY_H
#define DRMARRY_H

#include "hero.h"
#include "drmarrycard.h"

class DrMarry : public Hero
{
public:
    DrMarry(sf::RenderWindow*);
    virtual ~DrMarry();
    virtual void Attack(sf::Vector2i,Grid*,Grid*,std::vector<Hero*>&) override;
    virtual unsigned short int& getHealth() override;
    virtual unsigned short int& getPower() override;
    virtual sf::Vector2i& get_position_on_grid() override;
    void set_position_on_grid(sf::Vector2i);
    DrMarryCard drmarrycard ;
private:
};

#endif // DRMARRY_H
