#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

#include "general.h"
#include "game.h"
#include "grid.h"
#include "player.h"
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

class Menu
{
public:
    Menu();
    ~Menu();
    void exec();
private:
    sf::Texture MenuBackground;
    sf::Sprite MenuBackgroundSprite;
    sf::Font MenuFont;
    sf::Text option1;
    sf::Text option2;
    sf::Text option3;
    sf::Text option4;

    sf::RenderWindow* window;

    Game game;

    Player player1;
    Player player2;

    MrsGhost* Player1_MrsGhost;
    MrsGhost* Player2_MrsGhost;

    Robi* Player1_Robi;
    Robi* Player2_Robi;

    Leon* Player1_Leon;
    Leon* Player2_Leon;

    DrMarry* Player1_DrMarry;
    DrMarry* Player2_DrMarry;

    Snipper* Player1_Snipper;
    Snipper* Player2_Snipper;

    Kratos* Player1_Kratos;
    Kratos* Player2_Kratos;

    Giant* Player1_Giant;
    Giant* Player2_Giant;

    AlphaMan* Player1_AlphaMan;
    AlphaMan* Player2_AlphaMan;

    Professor* Player1_Professor;
    Professor* Player2_Professor;

    Commander* Player1_Commander;
    Commander* Player2_Commander;

    //MrsGhostCard* mrsghostcard ;
    //RobiCard* robicard ;
    LeonCard* leoncard ;
    DrMarryCard* drmarrycard ;
    SnipperCard* snippercard ;
    KratosCard* kratoscard ;
    GiantCard* giantcard ;
    //AlphaManCard* alphamancard ;
    ProfessorCard* professorcard  ;
    //CommanderCard* commandercard ;

    Grid* gridPlayer1 ;
    Grid* gridPlayer2;

    Grid* BattleField_P1;
    Grid* BattleField_P2;


};

#endif // MENU_H
