#include "giantcard.h"

using namespace sf;

GiantCard::GiantCard(sf::RenderWindow * window)
{
    this->window = window;
    CardTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/BigHeroesImage/Giant.png");
    CardTextureSprite.setTexture(CardTexture);
}

GiantCard::~GiantCard() {}

void GiantCard::draw()
{
    CardTextureSprite.setScale(Vector2f(0.3,0.3));
    CardTextureSprite.setPosition(Vector2f(1500,550));
    window->draw(CardTextureSprite);
}

void GiantCard::draw(sf::Vector2f CardScale, sf::Vector2f CardPosition)
{
    CardTextureSprite.setScale(CardScale);
    CardTextureSprite.setPosition(CardPosition);
    window->draw(CardTextureSprite);
}

sf::Sprite &GiantCard::getCardTextureSprite()
{
    return CardTextureSprite;
}
