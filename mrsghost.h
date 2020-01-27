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
    virtual void Attack() override;
    virtual bool isVisible() const override;
    void set_position_on_grid(sf::Vector2i);
    sf::Vector2i get_position_on_grid();
    MrsGhostCard mrsghostcard ;
private:
    unsigned short int VisibilityRate;
    sf::Vector2i position_on_grid;
   // sf::RenderWindow* window;
};

#endif // MRSGHOST_H
