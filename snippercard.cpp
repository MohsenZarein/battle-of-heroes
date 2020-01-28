#include "snippercard.h"
using namespace sf;

SnipperCard::SnipperCard(sf::RenderWindow * window)
{
    this->window = window;
    CardTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/BigHeroesImage/Snipper.png");
    CardTextureSprite.setTexture(CardTexture);
}

SnipperCard::~SnipperCard() {}

void SnipperCard::draw()
{
    CardTextureSprite.setScale(Vector2f(0.3,0.3));
    CardTextureSprite.setPosition(Vector2f(1350,250));
    window->draw(CardTextureSprite);
}

void SnipperCard::draw(sf::Vector2f CardScale, sf::Vector2f CardPosition)
{
    CardTextureSprite.setScale(CardScale);
    CardTextureSprite.setPosition(CardPosition);
    window->draw(CardTextureSprite);
}

sf::Sprite &SnipperCard::getCardTextureSprite()
{
    return CardTextureSprite;
}
