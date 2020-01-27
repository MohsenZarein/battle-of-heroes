#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "general.h"
#include "hero.h"
#include "grid.h"

class Player
{
public:
    Player();
    void SetHero(Hero*);
    std::vector<Hero*>& getHero();
    void WhichHeroIsSelected(sf::Vector2f,sf::Event);
private:
     std::vector<Hero*> HeroesOfPlayer;
};

#endif // PLAYER_H
