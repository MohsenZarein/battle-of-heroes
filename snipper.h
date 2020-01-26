#ifndef SNIPPER_H
#define SNIPPER_H

#include <hero.h>

class Snipper : public Hero
{
public:
    Snipper();
    virtual ~Snipper();
    virtual void Attack() override;
    virtual bool isVisible() const override;
    void set_position_on_grid(sf::Vector2i);
    sf::Vector2i get_position_on_grid();
private:
    sf::Vector2i position_on_grid;
};

#endif // SNIPPER_H
