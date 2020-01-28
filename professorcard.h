#ifndef PROFESSORCARD_H
#define PROFESSORCARD_H

#include "card.h"

class ProfessorCard : public Card
{
public:
    ProfessorCard(sf::RenderWindow*);
    virtual ~ProfessorCard();
    virtual void draw() override;
    virtual void draw(sf::Vector2f,sf::Vector2f) override;
    virtual sf::Sprite& getCardTextureSprite() override;
};

#endif // PROFESSORCARD_H
