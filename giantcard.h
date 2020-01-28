#ifndef GIANTCARD_H
#define GIANTCARD_H

#include "card.h"

class GiantCard : public Card
{
public:
    GiantCard(sf::RenderWindow*);
    virtual ~GiantCard();
    virtual void draw() override;
    virtual void draw(sf::Vector2f,sf::Vector2f) override;
    virtual sf::Sprite& getCardTextureSprite() override;
};

#endif // GIANTCARD_H
