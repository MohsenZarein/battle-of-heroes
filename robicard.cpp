#include "robicard.h"

using namespace sf;

RobiCard::RobiCard(RenderWindow* window)
{
    this->window = window;
    CardTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/BigHeroesImage/ROBI.png");
    CardTextureSprite.setTexture(CardTexture);

}

RobiCard::~RobiCard() {}

void RobiCard::draw()
{
    CardTextureSprite.setScale(Vector2f(0.25,0.25));
    CardTextureSprite.setPosition(Vector2f(1500,410));
    window->draw(CardTextureSprite);
}

void RobiCard::draw(Vector2f CardScale,Vector2f CardPosition , short int& health)
{
    CardTextureSprite.setScale(CardScale);
    CardTextureSprite.setPosition(CardPosition);

    CardName.setFont(CardFont);
    CardName.setString("Name : Robi");
    CardName.setCharacterSize(30);
    CardName.setFillColor(Color(0,255,127));
    CardName.setPosition(CardPosition.x + 115,CardPosition.y + 25);

    std::ostringstream oss;
    oss<<"Damage : "<<health;
    Damage.setFont(CardFont);
    Damage.setString(oss.str());
    Damage.setCharacterSize(30);
    Damage.setFillColor(Color(0,255,127));
    Damage.setPosition(CardPosition.x + 115,CardPosition.y + 50);

    Power.setFont(CardFont);
    Power.setString("Power : 2");
    Power.setCharacterSize(30);
    Power.setFillColor(Color(0,255,127));
    Power.setPosition(CardPosition.x + 115,CardPosition.y + 75);

    window->draw(CardName);
    window->draw(Damage);
    window->draw(Power);
    window->draw(CardTextureSprite);
}

Sprite &RobiCard::getCardTextureSprite()
{
    return CardTextureSprite;
}
