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
