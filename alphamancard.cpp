#include "alphamancard.h"

using namespace sf;

AlphaManCard::AlphaManCard(sf::RenderWindow* window)
{
    this->window = window;
    CardTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/BigHeroesImage/Alpha Man.png");
    CardTextureSprite.setTexture(CardTexture);
}

void AlphaManCard::draw()
{
    CardTextureSprite.setScale(Vector2f(0.3,0.3));
    CardTextureSprite.setPosition(Vector2f(1500,250));
    window->draw(CardTextureSprite);
}

void AlphaManCard::draw(sf::Vector2f CardScale, sf::Vector2f CardPosition)
{
    CardTextureSprite.setScale(CardScale);
    CardTextureSprite.setPosition(CardPosition);
    window->draw(CardTextureSprite);
}

sf::Sprite &AlphaManCard::getCardTextureSprite()
{
    return CardTextureSprite;
}
