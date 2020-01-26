#ifndef DRMARRY_H
#define DRMARRY_H

#include <hero.h>

class DrMarry : public Hero
{
public:
    DrMarry();
    virtual ~DrMarry();
    virtual void Attack() override;
    virtual bool isVisible() const override;
    void set_position_on_grid(sf::Vector2i);
    sf::Vector2i get_position_on_grid();
private:
    sf::Vector2i position_on_grid;
};

#endif // DRMARRY_H
