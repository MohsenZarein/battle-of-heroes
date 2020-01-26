#ifndef LEONCARD_H
#define LEONCARD_H

#include "card.h"

class LeonCard : public Card
{
public:
    LeonCard(sf::RenderWindow*);
    virtual void draw() override;
    virtual void draw(sf::Vector2f,sf::Vector2f) override;
    sf::Sprite& getCardTextureSprite();
private:
    sf::Texture CardTexture;
    sf::Sprite CardTextureSprite;
};

#endif // LEONCARD_H
