#include "game.h"

using namespace sf;

Game::Game()
{
    GameBackground.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/star-wars-ult-background-18.jpg");
    GameBackgroundSprite.setTexture(GameBackground);

    GameFont.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/Fonts/Lokananta.ttf");

    BeginingLoadPage.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/1920x1080-black-solid-color-background.jpg");
    BeginingLoadPageSprite.setTexture(BeginingLoadPage);

    ExpectationToStartTheGameTextue.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/427810.jpg");
    ExpToStTheGameTexSprite.setTexture(ExpectationToStartTheGameTextue);

    WinBackGround.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/681006.jpg");
    WinBackGroundSprite.setTexture(WinBackGround);

    ArrangeTeamsOption.setFont(GameFont);
    ArrangeTeamsOption.setString("Arrange Teames");
    ArrangeTeamsOption.setCharacterSize(70);
    ArrangeTeamsOption.setColor(Color::White);
    ArrangeTeamsOption.setPosition(0,0);

    BackOption.setFont(GameFont);
    BackOption.setString("Back");
    BackOption.setCharacterSize(70);
    BackOption.setColor(Color::White);
    BackOption.setPosition(0,70);

    NextPlayerOption.setFont(GameFont);
    NextPlayerOption.setString("Next player");
    NextPlayerOption.setCharacterSize(70);
    NextPlayerOption.setColor(Color::White);
    NextPlayerOption.setPosition(1440,0);

    GoToGameOption.setFont(GameFont);
    GoToGameOption.setString("GO TO GAME ...");
    GoToGameOption.setCharacterSize(70);
    GoToGameOption.setColor(Color::White);
    GoToGameOption.setPosition(1400,980);

    Loading.setFont(GameFont);
    Loading.setString("Loading . . . ");
    Loading.setCharacterSize(145);
    Loading.setColor(Color::White);
    Loading.setPosition(VideoMode::getDesktopMode().width/3,VideoMode::getDesktopMode().height/2 -50);

    BattleOfBasu.setFont(GameFont);
    BattleOfBasu.setString("BATTLE OF HEROES");
    BattleOfBasu.setCharacterSize(120);
    BattleOfBasu.setColor(Color::Red);
    BattleOfBasu.setPosition(VideoMode::getDesktopMode().width/4 -100,VideoMode::getDesktopMode().height/2 -50);

    Player1.setFont(GameFont);
    Player1.setString("PLAYER 1 GROUND");
    Player1.setCharacterSize(70);
    Player1.setFillColor(Color::White);
    Player1.setPosition(0,730);

    Player2.setFont(GameFont);
    Player2.setString("PLAYER 2 GROUND");
    Player2.setCharacterSize(70);
    Player2.setFillColor(Color::White);
    Player2.setPosition(0,730);

    Player1ChooseHeroToAttack.setFont(GameFont);
    Player1ChooseHeroToAttack.setString("PLAYER 1 / CHOOSE A HERO TO ATTACK :");
    Player1ChooseHeroToAttack.setCharacterSize(35);
    Player1ChooseHeroToAttack.setFillColor(Color::White);
    Player1ChooseHeroToAttack.setPosition(0,900);

    Player2ChooseHeroToAttack.setFont(GameFont);
    Player2ChooseHeroToAttack.setString("PLAYER 2 / CHOOSE A HERO TO ATTACK :");
    Player2ChooseHeroToAttack.setCharacterSize(35);
    Player2ChooseHeroToAttack.setFillColor(Color::White);
    Player2ChooseHeroToAttack.setPosition(0,900);

    Player1txt.setFont(GameFont);
    Player1txt.setString("Player 1");
    Player1txt.setCharacterSize(80);
    Player1txt.setFillColor(Color::White);
    Player1txt.setPosition(VideoMode::getDesktopMode().width/2+350,VideoMode::getDesktopMode().height/4);

    Player2txt.setFont(GameFont);
    Player2txt.setString("Player 2");
    Player2txt.setCharacterSize(80);
    Player2txt.setFillColor(Color::White);
    Player2txt.setPosition(VideoMode::getDesktopMode().width/2+350,VideoMode::getDesktopMode().height/4);

    Ready.setFont(GameFont);
    Ready.setString("Ready");
    Ready.setCharacterSize(80);
    Ready.setFillColor(Color::White);
    Ready.setPosition(VideoMode::getDesktopMode().width/2+400,VideoMode::getDesktopMode().height/4+100);

    to.setFont(GameFont);
    to.setString("to");
    to.setCharacterSize(80);
    to.setFillColor(Color::White);
    to.setPosition(VideoMode::getDesktopMode().width/2+450,VideoMode::getDesktopMode().height/4+200);

    Attack.setFont(GameFont);
    Attack.setString("Attack !");
    Attack.setCharacterSize(80);
    Attack.setFillColor(Color::White);
    Attack.setPosition(VideoMode::getDesktopMode().width/2+480,VideoMode::getDesktopMode().height/4+300);

    Player1Won.setFont(GameFont);
    Player1Won.setString("Player 1 Won!");
    Player1Won.setCharacterSize(145);
    Player1Won.setFillColor(Color::Black);
    Player1Won.setPosition(VideoMode::getDesktopMode().width/3,VideoMode::getDesktopMode().height/2 -50);

    Player2Won.setFont(GameFont);
    Player2Won.setString("Player 2 Won!");
    Player2Won.setCharacterSize(145);
    Player2Won.setFillColor(Color::Black);
    Player2Won.setPosition(VideoMode::getDesktopMode().width/3,VideoMode::getDesktopMode().height/2 -50);
}

int Game::checkWinningState(Player* player1, Player* player2,state& currentstate)
{
    short int Death_counter = 0;
    for(auto const &item : player1->getHero()) {
        if(item->getHealth() < 1)
            Death_counter++;
        if(Death_counter == player1->getHero().size()) {
          currentstate = WinningState;
          return 1;
        }
    }

    Death_counter = 0;

    for(auto const &item : player2->getHero()) {
        if(item->getHealth() < 1)
            Death_counter++;
        if(Death_counter == player2->getHero().size()) {
            currentstate = WinningState;
            return 2;
        }
    }
    return -1;
}

Sprite& Game::getGameBackgroundSprite()
{
    return GameBackgroundSprite;
}

Text& Game::getArrangeTeamsOption()
{
    return ArrangeTeamsOption;
}

Text& Game::getBackOption()
{
    return BackOption;
}

Text &Game::getNextPlayerOption()
{
    return NextPlayerOption;
}

Text &Game::getGoToGameOption()
{
    return GoToGameOption;
}

Sprite &Game::getBeginingLoadPageTextureSprite()
{
    return BeginingLoadPageSprite;
}

Text &Game::getLoading()
{
    return Loading;
}

Sprite &Game::getExpToStTheGameTexSprite()
{
    return ExpToStTheGameTexSprite;
}

Sprite &Game::getWinBackgroundSprite()
{
    return WinBackGroundSprite;
}

Text &Game::getBattleOfBasu()
{
    return BattleOfBasu;
}

Text &Game::getPlayer1Text()
{
    return Player1;
}

Text &Game::getPlayer2Text()
{
    return Player2;
}

Text &Game::getP1ChooseHeroToAttack()
{
    return Player1ChooseHeroToAttack;
}

Text &Game::getP2ChooseHeroToAttack()
{
    return Player2ChooseHeroToAttack;
}

Text &Game::getPlayer1Won()
{
    return Player1Won;
}

Text &Game::getPlayer2Won()
{
    return Player2Won;
}




