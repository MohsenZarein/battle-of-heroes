#ifndef ALPHAMANCARD_H
#define ALPHAMANCARD_H

#include "card.h"

class AlphaManCard : public Card
{
public:
    AlphaManCard(sf::RenderWindow*);
    virtual void draw() override;
    virtual void draw(sf::Vector2f,sf::Vector2f) override;
    sf::Sprite& getCardTextureSprite();
private:
    sf::Texture CardTexture;
    sf::Sprite CardTextureSprite;
};

#endif // ALPHAMANCARD_H
