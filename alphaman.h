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
    virtual bool isVisible() const override;
    void set_position_on_grid(sf::Vector2i);
    sf::Vector2i& get_position_on_grid();
    AlphaManCard alphamancard ;
private:

};

#endif // ALPHAMAN_H
