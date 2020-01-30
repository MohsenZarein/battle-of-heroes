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

void GiantCard::draw(sf::Vector2f CardScale, sf::Vector2f CardPosition , short int& health)
{
    CardTextureSprite.setScale(CardScale);
    CardTextureSprite.setPosition(CardPosition);

    CardName.setFont(CardFont);
    CardName.setString("Name : Giant");
    CardName.setCharacterSize(30);
    CardName.setFillColor(Color::Red);
    CardName.setPosition(CardPosition.x + 110,CardPosition.y + 35);

    std::ostringstream osss;
    osss<<"Damage : "<<health;
    Damage.setFont(CardFont);
    Damage.setString(osss.str());
    Damage.setCharacterSize(30);
    Damage.setFillColor(Color::Red);
    Damage.setPosition(CardPosition.x + 110,CardPosition.y + 60);

    window->draw(CardName);
    window->draw(Damage);
    window->draw(CardTextureSprite);
}

sf::Sprite &GiantCard::getCardTextureSprite()
{
    return CardTextureSprite;
}
