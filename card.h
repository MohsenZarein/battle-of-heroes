#ifndef CARD_H
#define CARD_H

#include <SFML/Graphics.hpp>

class Card
{
public:
    Card();
    virtual ~Card();
    virtual void draw() = 0;
    virtual void draw(sf::Vector2f,sf::Vector2f) = 0;
    virtual sf::Sprite& getCardTextureSprite() = 0;
protected:
    sf::RenderWindow* window;
    sf::Texture CardTexture;
    sf::Sprite CardTextureSprite;
};

#endif // CARD_H
