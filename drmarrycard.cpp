#include "drmarrycard.h"

using namespace sf;

DrMarryCard::DrMarryCard(sf::RenderWindow* window)
{
    this->window = window;
    CardTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/BigHeroesImage/Dr Marry.png");
    CardTextureSprite.setTexture(CardTexture);
}

DrMarryCard::~DrMarryCard() {}

void DrMarryCard::draw()
{
    CardTextureSprite.setScale(Vector2f(0.3,0.3));
    CardTextureSprite.setPosition(Vector2f(1200,250));
    window->draw(CardTextureSprite);
}

void DrMarryCard::draw(Vector2f CardScale, Vector2f CardPosition)
{
    CardTextureSprite.setScale(CardScale);
    CardTextureSprite.setPosition(CardPosition);
    window->draw(CardTextureSprite);
}

Sprite &DrMarryCard::getCardTextureSprite()
{
    return CardTextureSprite;
}
