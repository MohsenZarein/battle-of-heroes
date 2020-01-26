#ifndef COMMANDERCARD_H
#define COMMANDERCARD_H

#include <card.h>

class CommanderCard : public Card
{
public:
    CommanderCard(sf::RenderWindow*);
    virtual void draw() override;
    virtual void draw(sf::Vector2f,sf::Vector2f) override;
    sf::Sprite& getCardTextureSprite();
private:
    sf::Texture CardTexture;
    sf::Sprite CardTextureSprite;
};

#endif // COMMANDERCARD_H
