#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "hero.h"
#include "professorcard.h"

class Professor : public Hero
{
public:
    Professor(sf::RenderWindow*);
    virtual ~Professor();
    virtual void Attack(sf::Vector2i,Grid*,std::vector<Hero*>&) override;
    virtual bool isVisible() const override;
    void set_position_on_grid(sf::Vector2i);
    sf::Vector2i& get_position_on_grid();
    ProfessorCard professorcard ;
private:
};

#endif // PROFESSOR_H
