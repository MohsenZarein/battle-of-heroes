#ifndef ROBI_H
#define ROBI_H

#include "hero.h"
#include "robicard.h"

class Robi : public Hero
{
public:
    Robi(sf::RenderWindow*);
    virtual ~Robi();
    virtual void Attack(sf::Vector2i,Grid*,std::vector<Hero*>&) override;
    virtual float& getHealth() override;
    virtual unsigned short int& getPower() override;
    virtual sf::Vector2i& get_position_on_grid() override;
    void set_position_on_grid(sf::Vector2i);
    RobiCard robicard ;
private:
};

#endif // ROBI_H
