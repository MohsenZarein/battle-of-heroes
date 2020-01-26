#ifndef MRSGHOSTCARD_H
#define MRSGHOSTCARD_H

#include <card.h>

class MrsGhostCard : public Card
{
public:
    MrsGhostCard(sf::RenderWindow*);
    virtual void draw() override;
    virtual void draw(sf::Vector2f,sf::Vector2f) override;
    sf::Sprite& getCardTextureSprite();
private:
    sf::Texture CardTexture;
    sf::Sprite CardTextureSprite;
};

#endif // MRSGHOSTCARD_H
