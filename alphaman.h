#ifndef ALPHAMAN_H
#define ALPHAMAN_H

#include "hero.h"
#include "alphamancard.h"

class AlphaMan : public Hero
{
public:
    AlphaMan(sf::RenderWindow*);
    virtual ~AlphaMan();
    virtual void Attack(sf::Vector2i,Grid*,std::vector<Hero*>&) override;
    virtual float& getHealth() override;
    virtual unsigned short int& getPower() override;
    virtual sf::Vector2i& get_position_on_grid() override;
    void set_position_on_grid(sf::Vector2i);
    AlphaManCard alphamancard ;
private:

};

#endif // ALPHAMAN_H
