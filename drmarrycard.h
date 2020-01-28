#ifndef DRMARRYCARD_H
#define DRMARRYCARD_H

#include <card.h>

class DrMarryCard : public Card
{
public:
    DrMarryCard(sf::RenderWindow*);
    virtual ~DrMarryCard();
    virtual void draw() override;
    virtual void draw(sf::Vector2f,sf::Vector2f) override;
    virtual sf::Sprite& getCardTextureSprite() override;
};

#endif // DRMARRYCARD_H
