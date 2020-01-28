#ifndef MRSGHOST_H
#define MRSGHOST_H

#include "hero.h"
#include <SFML/Graphics.hpp>
#include "mrsghostcard.h"

class MrsGhost : public Hero
{
public:
    MrsGhost(sf::RenderWindow*);
    virtual ~MrsGhost();
    virtual void Attack(sf::Vector2i,Grid*,std::vector<Hero*>&) override;
    virtual bool isVisible() const override;
    void set_position_on_grid(sf::Vector2i);
    sf::Vector2i& get_position_on_grid();
    MrsGhostCard mrsghostcard ;
private:
    unsigned short int VisibilityRate;
};

#endif // MRSGHOST_H
