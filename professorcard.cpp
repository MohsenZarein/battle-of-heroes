#include "professorcard.h"

using namespace sf;

ProfessorCard::ProfessorCard(sf::RenderWindow *window)
{
    this->window = window;
    CardTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/BigHeroesImage/Professor.png");
    CardTextureSprite.setTexture(CardTexture);
}

ProfessorCard::~ProfessorCard() {}

void ProfessorCard::draw()
{
    CardTextureSprite.setScale(Vector2f(0.3,0.3));
    CardTextureSprite.setPosition(Vector2f(1350,400));
    window->draw(CardTextureSprite);
}

void ProfessorCard::draw(sf::Vector2f CardScale, sf::Vector2f CardPosition , short int& health)
{
    CardTextureSprite.setScale(CardScale);
    CardTextureSprite.setPosition(CardPosition);

    CardName.setFont(CardFont);
    CardName.setString("Name : Professor");
    CardName.setCharacterSize(30);
    CardName.setFillColor(Color(124,252,0));
    CardName.setPosition(CardPosition.x + 110,CardPosition.y + 35);

    std::ostringstream oss;
    oss<<"Damage : "<<health;
    Damage.setFont(CardFont);
    Damage.setString(oss.str());
    Damage.setCharacterSize(30);
    Damage.setFillColor(Color(124,252,0));
    Damage.setPosition(CardPosition.x + 110,CardPosition.y + 60);

    window->draw(CardName);
    window->draw(Damage);
    window->draw(CardTextureSprite);
}

sf::Sprite& ProfessorCard::getCardTextureSprite()
{
    return CardTextureSprite;
}
