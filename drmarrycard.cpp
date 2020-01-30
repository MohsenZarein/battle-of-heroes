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

void DrMarryCard::draw(Vector2f CardScale, Vector2f CardPosition , short int& health)
{
    CardTextureSprite.setScale(CardScale);
    CardTextureSprite.setPosition(CardPosition);

    CardName.setFont(CardFont);
    CardName.setString("Name : Dr.Marry");
    CardName.setCharacterSize(30);
    CardName.setFillColor(Color(250,128,114));
    CardName.setPosition(CardPosition.x + 110,CardPosition.y + 35);

    std::ostringstream osss;
    osss<<"Damage : "<<health;
    Damage.setFont(CardFont);
    Damage.setString(osss.str());
    Damage.setCharacterSize(30);
    Damage.setFillColor(Color(250,128,114));
    Damage.setPosition(CardPosition.x + 110,CardPosition.y + 60);

    window->draw(CardName);
    window->draw(Damage);
    window->draw(CardTextureSprite);
}

Sprite &DrMarryCard::getCardTextureSprite()
{
    return CardTextureSprite;
}
