#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "general.h"
#include "hero.h"
#include "grid.h"

#include "mrsghostcard.h"
#include "mrsghost.h"
#include "robicard.h"
#include "robi.h"
#include "leoncard.h"
#include "leon.h"
#include "drmarrycard.h"
#include "drmarry.h"
#include "snippercard.h"
#include "snipper.h"
#include "kratoscard.h"
#include "kratos.h"
#include "giantcard.h"
#include "giant.h"
#include "alphamancard.h"
#include "alphaman.h"
#include "professorcard.h"
#include "professor.h"
#include "commandercard.h"
#include "commander.h"

class Player
{
public:
    Player(const std::string,sf::RenderWindow*);
    ~Player();
    void SetHero(Hero*);
    std::vector<Hero*>& getHero();
    void WhichHeroIsSelected(sf::Vector2f,Heroes&);
    std::string PlayerName;

    //MrsGhost* Player1_MrsGhost;
    MrsGhost* mrsghost;

    //Robi* Player1_Robi;
    Robi* robi;

    //Leon* Player1_Leon;
    Leon* leon;

    //DrMarry* Player1_DrMarry;
    DrMarry* drmarry;

    //Snipper* Player1_Snipper;
    Snipper* snipper;

    //Kratos* Player1_Kratos;
    Kratos* kratos;

    //Giant* Player1_Giant;
    Giant* giant;

    //AlphaMan* Player1_AlphaMan;
    AlphaMan* alphaman;

    //Professor* Player1_Professor;
    Professor* professor;

    //Commander* Player1_Commander;
    Commander* commander;
private:
    std::vector<Hero*> HeroesOfPlayer;
    sf::RenderWindow* window;
};

#endif // PLAYER_H
