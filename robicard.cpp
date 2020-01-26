#include "robicard.h"

using namespace sf;

RobiCard::RobiCard(RenderWindow* window)
{
    this->window = window;
    CardTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/BigHeroesImage/ROBI.png");
    CardTextureSprite.setTexture(CardTexture);

}

void RobiCard::draw()
{
    CardTextureSprite.setScale(Vector2f(0.25,0.25));
    CardTextureSprite.setPosition(Vector2f(1500,410));
    window->draw(CardTextureSprite);
}

void RobiCard::draw(Vector2f CardScale,Vector2f CardPosition)
{
    CardTextureSprite.setScale(CardScale);
    CardTextureSprite.setPosition(CardPosition);
    window->draw(CardTextureSprite);
}

Sprite &RobiCard::getCardTextureSprite()
{
    return CardTextureSprite;
}
