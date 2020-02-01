#include "snippercard.h"
using namespace sf;

SnipperCard::SnipperCard(sf::RenderWindow * window)
{
    this->window = window;
    CardTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/BigHeroesImage/Snipper.png");
    CardTextureSprite.setTexture(CardTexture);
}

SnipperCard::~SnipperCard() {}

void SnipperCard::draw()
{
    CardTextureSprite.setScale(Vector2f(0.3,0.3));
    CardTextureSprite.setPosition(Vector2f(1350,250));
    window->draw(CardTextureSprite);
}

void SnipperCard::draw(sf::Vector2f CardScale, sf::Vector2f CardPosition , short int& health)
{
    CardTextureSprite.setScale(CardScale);
    CardTextureSprite.setPosition(CardPosition);

    CardName.setFont(CardFont);
    CardName.setString("Name : Snipper");
    CardName.setCharacterSize(30);
    CardName.setFillColor(Color::Yellow);
    CardName.setPosition(CardPosition.x + 110,CardPosition.y + 25);

    std::ostringstream oss;
    oss<<"Damage : "<<health;
    Damage.setFont(CardFont);
    Damage.setString(oss.str());
    Damage.setCharacterSize(30);
    Damage.setFillColor(Color::Yellow);
    Damage.setPosition(CardPosition.x + 110,CardPosition.y + 50);

    Power.setFont(CardFont);
    Power.setString("Power : 4");
    Power.setCharacterSize(30);
    Power.setFillColor(Color::Yellow);
    Power.setPosition(CardPosition.x + 110,CardPosition.y + 75);

    window->draw(CardName);
    window->draw(Damage);
    window->draw(Power);
    window->draw(CardTextureSprite);
}

sf::Sprite &SnipperCard::getCardTextureSprite()
{
    return CardTextureSprite;
}
