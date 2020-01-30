#ifndef ALPHAMANCARD_H
#define ALPHAMANCARD_H

#include "card.h"

class AlphaManCard : public Card
{
public:
    AlphaManCard(sf::RenderWindow*);
    virtual ~AlphaManCard();
    virtual void draw() override;
    virtual void draw(sf::Vector2f,sf::Vector2f,short int&) override;
    virtual sf::Sprite& getCardTextureSprite() override;
};

#endif // ALPHAMANCARD_H
