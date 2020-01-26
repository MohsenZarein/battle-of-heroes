#ifndef DRMARRYCARD_H
#define DRMARRYCARD_H

#include <card.h>

class DrMarryCard : public Card
{
public:
    DrMarryCard(sf::RenderWindow*);
    virtual void draw() override;
    virtual void draw(sf::Vector2f,sf::Vector2f) override;
    sf::Sprite& getCardTextureSprite();
private:
    sf::Texture CardTexture;
    sf::Sprite CardTextureSprite;
};

#endif // DRMARRYCARD_H
