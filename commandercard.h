#ifndef COMMANDERCARD_H
#define COMMANDERCARD_H

#include "card.h"

class CommanderCard : public Card
{
public:
    CommanderCard(sf::RenderWindow*);
    virtual ~CommanderCard();
    virtual void draw() override;
    virtual void draw(sf::Vector2f,sf::Vector2f,short int&) override;
    virtual sf::Sprite& getCardTextureSprite() override;
};

#endif // COMMANDERCARD_H
