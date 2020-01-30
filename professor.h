#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "hero.h"
#include "professorcard.h"

class Professor : public Hero
{
public:
    Professor(sf::RenderWindow*);
    virtual ~Professor();
    virtual void Attack(sf::Vector2i,Grid*,Grid*,std::vector<Hero*>&) override;
    virtual short int& getHealth() override;
    virtual unsigned short int& getPower() override;
    virtual sf::Vector2i& get_position_on_grid() override;
    void set_position_on_grid(sf::Vector2i);
    ProfessorCard professorcard ;
private:
};

#endif // PROFESSOR_H
