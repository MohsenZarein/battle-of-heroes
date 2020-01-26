#ifndef PROFESSORCARD_H
#define PROFESSORCARD_H

#include "card.h"

class ProfessorCard : public Card
{
public:
    ProfessorCard(sf::RenderWindow*);
    virtual void draw() override;
    virtual void draw(sf::Vector2f,sf::Vector2f) override;
    sf::Sprite& getCardTextureSprite();
private:
    sf::Texture CardTexture;
    sf::Sprite CardTextureSprite;
};

#endif // PROFESSORCARD_H
