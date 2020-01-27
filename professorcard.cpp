#include "professorcard.h"

using namespace sf;

ProfessorCard::ProfessorCard(sf::RenderWindow *window)
{
    this->window = window;
    CardTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/BigHeroesImage/Professor.png");
    CardTextureSprite.setTexture(CardTexture);
}

void ProfessorCard::draw()
{
    CardTextureSprite.setScale(Vector2f(0.3,0.3));
    CardTextureSprite.setPosition(Vector2f(1350,400));
    window->draw(CardTextureSprite);
}

void ProfessorCard::draw(sf::Vector2f CardScale, sf::Vector2f CardPosition)
{
    CardTextureSprite.setScale(CardScale);
    CardTextureSprite.setPosition(CardPosition);
    window->draw(CardTextureSprite);
}

sf::Sprite& ProfessorCard::getCardTextureSprite()
{
    return CardTextureSprite;
}
