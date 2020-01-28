#include "commandercard.h"

using namespace sf;

CommanderCard::CommanderCard(sf::RenderWindow *window)
{
    this->window = window;
    CardTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/BigHeroesImage/Commander.png");
    CardTextureSprite.setTexture(CardTexture);
}

CommanderCard::~CommanderCard() {}

void CommanderCard::draw()
{
    CardTextureSprite.setScale(Vector2f(0.3,0.3));
    CardTextureSprite.setPosition(Vector2f(1200,400));
    window->draw(CardTextureSprite);
}

void CommanderCard::draw(sf::Vector2f CardScale, sf::Vector2f CardPosition)
{
    CardTextureSprite.setScale(CardScale);
    CardTextureSprite.setPosition(CardPosition);
    window->draw(CardTextureSprite);
}

sf::Sprite &CommanderCard::getCardTextureSprite()
{
    return CardTextureSprite;
}
