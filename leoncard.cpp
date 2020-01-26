#include "leoncard.h"

using namespace sf;

LeonCard::LeonCard(sf::RenderWindow *window)
{
    this->window = window;
    CardTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/BigHeroesImage/Leon.png");
    CardTextureSprite.setTexture(CardTexture);
}


void LeonCard::draw()
{
    CardTextureSprite.setScale(Vector2f(0.2,0.2));
    CardTextureSprite.setPosition(Vector2f(1650,280));
    window->draw(CardTextureSprite);
}

void LeonCard::draw(Vector2f CardScale, Vector2f CardPosition)
{
    CardTextureSprite.setScale(CardScale);
    CardTextureSprite.setPosition(CardPosition);
    window->draw(CardTextureSprite);
}

Sprite &LeonCard::getCardTextureSprite()
{
    return CardTextureSprite;
}
