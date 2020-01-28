#ifndef ROBICARD_H
#define ROBICARD_H

#include <card.h>

class RobiCard : public Card
{
public:
    RobiCard(sf::RenderWindow*);
    virtual ~RobiCard();
    virtual void draw() override;
    virtual void draw(sf::Vector2f,sf::Vector2f) override;
    virtual sf::Sprite& getCardTextureSprite() override;
};

#endif // ROBICARD_H
