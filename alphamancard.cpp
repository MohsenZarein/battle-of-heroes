#include "alphamancard.h"

using namespace sf;

AlphaManCard::AlphaManCard(sf::RenderWindow* window)
{
    this->window = window;
    CardTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/BigHeroesImage/Alpha Man.png");
    CardTextureSprite.setTexture(CardTexture);
}

AlphaManCard::~AlphaManCard() {}

void AlphaManCard::draw()
{
    CardTextureSprite.setScale(Vector2f(0.3,0.3));
    CardTextureSprite.setPosition(Vector2f(1500,250));
    window->draw(CardTextureSprite);
}

void AlphaManCard::draw(sf::Vector2f CardScale, sf::Vector2f CardPosition , short int& health)
{
    CardTextureSprite.setScale(CardScale);
    CardTextureSprite.setPosition(CardPosition);

    CardName.setFont(CardFont);
    CardName.setString("Name : Alphaman");
    CardName.setCharacterSize(30);
    CardName.setFillColor(Color(0,191,255));
    CardName.setPosition(CardPosition.x + 110,CardPosition.y + 35);

    std::ostringstream osss;
    osss<<"Damage : "<<health;
    Damage.setFont(CardFont);
    Damage.setString(osss.str());
    Damage.setCharacterSize(30);
    Damage.setFillColor(Color(0,191,255));
    Damage.setPosition(CardPosition.x + 110,CardPosition.y + 60);

    window->draw(CardName);
    window->draw(Damage);
    window->draw(CardTextureSprite);
}

sf::Sprite &AlphaManCard::getCardTextureSprite()
{
    return CardTextureSprite;
}
