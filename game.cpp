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
    Player1.setFillColor(Color::Black);
    Player1.setPosition(0,730);

    Player2.setFont(GameFont);
    Player2.setString("PLAYER 2 GROUND");
    Player2.setCharacterSize(70);
    Player2.setFillColor(Color::Black);
    Player2.setPosition(0,730);


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


