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
    virtual void Attack(sf::Vector2i,Grid*,Grid*,std::vector<Hero*>&) override;
    virtual unsigned short int& getHealth() override;
    virtual unsigned short int& getPower() override;
    virtual sf::Vector2i& get_position_on_grid() override;
    bool& isVisible();
    void ChangeVisibility(bool);
    void set_position_on_grid(sf::Vector2i);
    MrsGhostCard mrsghostcard ;
private:
    bool visibility;
};

#endif // MRSGHOST_H
