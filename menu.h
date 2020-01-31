#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>

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
    sf::SoundBuffer ShutgunBuffer;
    sf::Sound Shutgun;
    //sf::Music GameMainMusic;
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

    Player* player1;
    Player* player2;

    Grid* gridPlayer1 ;
    Grid* gridPlayer2;

    Grid* BattleField_P1;
    Grid* BattleField_P2;


};

#endif // MENU_H
