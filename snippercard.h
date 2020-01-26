#ifndef SNIPPERCARD_H
#define SNIPPERCARD_H

#include "card.h"

class SnipperCard : public Card
{
public:
    SnipperCard(sf::RenderWindow*);
    virtual void draw() override;
    virtual void draw(sf::Vector2f,sf::Vector2f) override;
    sf::Sprite& getCardTextureSprite();
private:
    sf::Texture CardTexture;
    sf::Sprite CardTextureSprite;
};

#endif // SNIPPERCARD_H
