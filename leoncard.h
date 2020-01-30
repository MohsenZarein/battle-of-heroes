#ifndef LEONCARD_H
#define LEONCARD_H

#include "card.h"

class LeonCard : public Card
{
public:
    LeonCard(sf::RenderWindow*);
    virtual ~LeonCard();
    virtual void draw() override;
    virtual void draw(sf::Vector2f,sf::Vector2f,short int&) override;
    virtual sf::Sprite& getCardTextureSprite() override;
};

#endif // LEONCARD_H
