#include "player.h"

Player::Player()
{

}

void Player::SetHero(Hero* a_Hero)
{
    HeroesOfPlayer.push_back(a_Hero);
}

std::vector<Hero *> &Player::getHero()
{
    return HeroesOfPlayer;
}

/*void Player::WhichHeroIsSelected(sf::Vector2f pos,sf::Event event)
{
    for(auto const &item : HeroesOfPlayer) {
        if(item->) {
            item->car
        }
    }
}*/
