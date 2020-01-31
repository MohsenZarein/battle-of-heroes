#include "leoncard.h"

using namespace sf;

LeonCard::LeonCard(sf::RenderWindow *window)
{
    this->window = window;
    CardTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/BigHeroesImage/Leon.png");
    CardTextureSprite.setTexture(CardTexture);
}

LeonCard::~LeonCard() {}


void LeonCard::draw()
{
    CardTextureSprite.setScale(Vector2f(0.2,0.2));
    CardTextureSprite.setPosition(Vector2f(1650,280));
    window->draw(CardTextureSprite);
}

void LeonCard::draw(Vector2f CardScale, Vector2f CardPosition , short int& health)
{
    CardTextureSprite.setScale(Vector2f(0.2,0.2));
    CardTextureSprite.setPosition(CardPosition);

    CardName.setFont(CardFont);
    CardName.setString("Name : Leon");
    CardName.setCharacterSize(30);
    CardName.setFillColor(Color(220,20,60));
    CardName.setPosition(CardPosition.x + 110,CardPosition.y + 35);

    std::ostringstream oss;
    oss<<"Damage : "<<health;
    Damage.setFont(CardFont);
    Damage.setString(oss.str());
    Damage.setCharacterSize(30);
    Damage.setFillColor(Color(220,20,60));
    Damage.setPosition(CardPosition.x + 110,CardPosition.y + 60);

    window->draw(CardName);
    window->draw(Damage);
    window->draw(CardTextureSprite);
}

Sprite &LeonCard::getCardTextureSprite()
{
    return CardTextureSprite;
}
