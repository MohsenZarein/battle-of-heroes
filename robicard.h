#ifndef ROBICARD_H
#define ROBICARD_H

#include <card.h>

class RobiCard : public Card
{
public:
    RobiCard(sf::RenderWindow*);
    virtual void draw() override;
    virtual void draw(sf::Vector2f,sf::Vector2f) override;
    sf::Sprite& getCardTextureSprite();
private:
    sf::Texture CardTexture;
    sf::Sprite CardTextureSprite;
};

#endif // ROBICARD_H
