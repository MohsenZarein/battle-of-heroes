#ifndef SNIPPERCARD_H
#define SNIPPERCARD_H

#include "card.h"

class SnipperCard : public Card
{
public:
    SnipperCard(sf::RenderWindow*);
    virtual ~SnipperCard();
    virtual void draw() override;
    virtual void draw(sf::Vector2f,sf::Vector2f,short int&) override;
    virtual sf::Sprite& getCardTextureSprite() override;
};

#endif // SNIPPERCARD_H
