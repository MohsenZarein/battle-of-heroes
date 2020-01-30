#ifndef MRSGHOSTCARD_H
#define MRSGHOSTCARD_H

#include <card.h>

class MrsGhostCard : public Card
{
public:
    MrsGhostCard(sf::RenderWindow*);
    virtual ~MrsGhostCard();
    virtual void draw() override;
    virtual void draw(sf::Vector2f,sf::Vector2f,short int&) override;
    virtual sf::Sprite& getCardTextureSprite() override;
};

#endif // MRSGHOSTCARD_H
