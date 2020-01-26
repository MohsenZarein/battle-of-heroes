#include "kratoscard.h"

using namespace sf;

KratosCard::KratosCard(sf::RenderWindow * window)
{
    this->window = window;
    CardTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/BigHeroesImage/Kratos.png");
    CardTextureSprite.setTexture(CardTexture);
}

void KratosCard::draw()
{
    CardTextureSprite.setScale(Vector2f(0.3,0.3));
    CardTextureSprite.setPosition(Vector2f(1650,400));
    window->draw(CardTextureSprite);
}

void KratosCard::draw(sf::Vector2f CardScale, sf::Vector2f CardPosition)
{
    CardTextureSprite.setScale(CardScale);
    CardTextureSprite.setPosition(CardPosition);
    window->draw(CardTextureSprite);
}

sf::Sprite &KratosCard::getCardTextureSprite()
{
    return CardTextureSprite;
}
