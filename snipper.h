#ifndef SNIPPER_H
#define SNIPPER_H

#include "hero.h"
#include "snippercard.h"

class Snipper : public Hero
{
public:
    Snipper(sf::RenderWindow*);
    virtual ~Snipper();
    virtual void Attack(sf::Vector2i,Grid*,std::vector<Hero*>&) override;
    virtual bool isVisible() const override;
    void set_position_on_grid(sf::Vector2i);
    sf::Vector2i& get_position_on_grid();
    SnipperCard snippercard ;
private:
};

#endif // SNIPPER_H
