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

void CommanderCard::draw(sf::Vector2f CardScale, sf::Vector2f CardPosition , short int& health)
{
    CardTextureSprite.setScale(CardScale);
    CardTextureSprite.setPosition(CardPosition);

    CardName.setFont(CardFont);
    CardName.setString("Name : Commander");
    CardName.setCharacterSize(30);
    CardName.setFillColor(Color(180,0,0));
    CardName.setPosition(CardPosition.x + 110,CardPosition.y + 25);

    std::ostringstream oss;
    oss<<"Damage : "<<health;
    Damage.setFont(CardFont);
    Damage.setString(oss.str());
    Damage.setCharacterSize(30);
    Damage.setFillColor(Color(180,0,0));
    Damage.setPosition(CardPosition.x + 110,CardPosition.y + 50);

    Power.setFont(CardFont);
    Power.setString("Power : 3");
    Power.setCharacterSize(30);
    Power.setFillColor(Color(180,0,0));
    Power.setPosition(CardPosition.x + 110,CardPosition.y + 75);

    window->draw(CardName);
    window->draw(Damage);
    window->draw(Power);
    window->draw(CardTextureSprite);
}

sf::Sprite &CommanderCard::getCardTextureSprite()
{
    return CardTextureSprite;
}
