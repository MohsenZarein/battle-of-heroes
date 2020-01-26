#ifndef GIANTCARD_H
#define GIANTCARD_H

#include "card.h"

class GiantCard : public Card
{
public:
    GiantCard(sf::RenderWindow*);
    virtual void draw() override;
    virtual void draw(sf::Vector2f,sf::Vector2f) override;
    sf::Sprite& getCardTextureSprite();
private:
    sf::Texture CardTexture;
    sf::Sprite CardTextureSprite;
};

#endif // GIANTCARD_H
