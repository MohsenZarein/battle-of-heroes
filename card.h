#ifndef CARD_H
#define CARD_H

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <string>

class Card
{
public:
    Card();
    virtual ~Card();
    virtual void draw() = 0;
    virtual void draw(sf::Vector2f,sf::Vector2f,short int&) = 0;
    virtual sf::Sprite& getCardTextureSprite() = 0;
    sf::Texture CardTexture;
protected:
    sf::RenderWindow* window;
    sf::Sprite CardTextureSprite;
    sf::Text CardName;
    sf::Text Damage;
    sf::Text Power;
    sf::Font CardFont;
};

#endif // CARD_H
