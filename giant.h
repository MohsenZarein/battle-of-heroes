#ifndef GIANT_H
#define GIANT_H

#include <hero.h>

class Giant : public Hero
{
public:
    Giant();
    virtual ~Giant();
    virtual void Attack() override;
    virtual bool isVisible() const override;
    void set_position_on_grid(sf::Vector2i);
    sf::Vector2i get_position_on_grid();
private:
    sf::Vector2i position_on_grid;
};

#endif // GIANT_H
