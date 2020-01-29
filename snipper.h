#ifndef SNIPPER_H
#define SNIPPER_H

#include "hero.h"
#include "snippercard.h"

class Snipper : public Hero
{
public:
    Snipper(sf::RenderWindow*);
    virtual ~Snipper();
    virtual void Attack(sf::Vector2i,Grid*,Grid*,std::vector<Hero*>&) override;
    virtual unsigned short int& getHealth() override;
    virtual unsigned short int& getPower() override;
    virtual sf::Vector2i& get_position_on_grid() override;
    void set_position_on_grid(sf::Vector2i);
    SnipperCard snippercard ;
private:
};

#endif // SNIPPER_H
