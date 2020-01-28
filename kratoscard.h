#ifndef KRATOSCARD_H
#define KRATOSCARD_H

#include "card.h"

class KratosCard : public Card
{
public:
    KratosCard(sf::RenderWindow*);
    virtual ~KratosCard();
    virtual void draw() override;
    virtual void draw(sf::Vector2f,sf::Vector2f) override;
    virtual sf::Sprite& getCardTextureSprite() override;
};

#endif // KRATOSCARD_H
