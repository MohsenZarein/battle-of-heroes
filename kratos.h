#ifndef KRATOS_H
#define KRATOS_H

#include "hero.h"
#include "kratoscard.h"

class Kratos : public Hero
{
public:
    Kratos(sf::RenderWindow*);
    virtual ~Kratos();
    virtual void Attack() override;
    virtual bool isVisible() const override;
    void set_position_on_grid(sf::Vector2i);
    sf::Vector2i get_position_on_grid();
    KratosCard kratoscard ;
private:
    sf::Vector2i position_on_grid;
};

#endif // KRATOS_H
