#ifndef ROBI_H
#define ROBI_H

#include <SFML/Graphics.hpp>
#include <hero.h>

class Robi : public Hero
{
public:
    Robi();
    virtual ~Robi();
    virtual void Attack() override;
    virtual bool isVisible() const override;
    void set_position_on_grid(sf::Vector2i);
    sf::Vector2i get_position_on_grid();
private:
    sf::Vector2i position_on_grid;
};

#endif // ROBI_H
