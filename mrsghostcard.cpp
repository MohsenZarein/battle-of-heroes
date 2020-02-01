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

void MrsGhostCard::draw(Vector2f CardScale, Vector2f CardPosition , short int& health)
{
    CardTextureSprite.setScale(CardScale);
    CardTextureSprite.setPosition(CardPosition);

    CardName.setFont(CardFont);
    CardName.setString("Name : Mrs.Ghost");
    CardName.setCharacterSize(30);
    CardName.setFillColor(Color(255,255,102));
    CardName.setPosition(CardPosition.x + 110,CardPosition.y + 25);

    Damage.setFont(CardFont);
    Damage.setString("Damage : ?");
    Damage.setCharacterSize(30);
    Damage.setFillColor(Color(255,255,102));
    Damage.setPosition(CardPosition.x + 110,CardPosition.y + 50);

    Power.setFont(CardFont);
    Power.setString("Power : 3");
    Power.setCharacterSize(30);
    Power.setFillColor(Color(255,255,102));
    Power.setPosition(CardPosition.x + 110,CardPosition.y + 75);

    window->draw(CardName);
    window->draw(Damage);
    window->draw(Power);
    window->draw(CardTextureSprite);
}


Sprite& MrsGhostCard::getCardTextureSprite()
{
    return CardTextureSprite;
}

