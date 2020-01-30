#ifndef KRATOS_H
#define KRATOS_H

#include "hero.h"
#include "kratoscard.h"

class Kratos : public Hero
{
public:
    Kratos(sf::RenderWindow*);
    virtual ~Kratos();
    virtual void Attack(sf::Vector2i,Grid*,Grid*,std::vector<Hero*>&) override;
    virtual short int& getHealth() override;
    virtual unsigned short int& getPower() override;
    virtual sf::Vector2i& get_position_on_grid() override;
    void set_position_on_grid(sf::Vector2i);
    KratosCard kratoscard ;
private:
};

#endif // KRATOS_H
