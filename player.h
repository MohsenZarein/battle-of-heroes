#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "hero.h"
#include "grid.h"

class Player
{
public:
    Player();
    void SetHero(Hero*);
    std::vector<Hero*>& getHero();
private:
     std::vector<Hero*> HeroesOfPlayer;
};

#endif // PLAYER_H
