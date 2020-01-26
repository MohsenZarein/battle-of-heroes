#ifndef KRATOSCARD_H
#define KRATOSCARD_H

#include "card.h"

class KratosCard : public Card
{
public:
    KratosCard(sf::RenderWindow*);
    virtual void draw() override;
    virtual void draw(sf::Vector2f,sf::Vector2f) override;
    sf::Sprite& getCardTextureSprite();
private:
    sf::Texture CardTexture;
    sf::Sprite CardTextureSprite;
};

#endif // KRATOSCARD_H
