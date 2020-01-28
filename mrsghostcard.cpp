#include "mrsghostcard.h"


using namespace sf;

MrsGhostCard::MrsGhostCard(RenderWindow* window)
{
    this->window = window;
    CardTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/BigHeroesImage/Mrs. Ghost.png");
    CardTextureSprite.setTexture(CardTexture);
}

MrsGhostCard::~MrsGhostCard() {}


void MrsGhostCard::draw()
{
    CardTextureSprite.setScale(Vector2f(0.3,0.3));
    CardTextureSprite.setPosition(Vector2f(1370,550));
    window->draw(CardTextureSprite);
}

void MrsGhostCard::draw(Vector2f CardScale, Vector2f CardPosition)
{
    CardTextureSprite.setScale(CardScale);
    CardTextureSprite.setPosition(CardPosition);
    window->draw(CardTextureSprite);
}


Sprite& MrsGhostCard::getCardTextureSprite()
{
    return CardTextureSprite;
}

