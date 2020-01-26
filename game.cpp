#include "game.h"

using namespace sf;

Game::Game()
{
    GameBackground.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/star-wars-ult-background-18.jpg");
    GameBackgroundSprite.setTexture(GameBackground);

    GameFont.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/Fonts/TarrgetLaserRegular-4OE9.otf");

    BeginingLoadPage.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/1920x1080-black-solid-color-background.jpg");
    BeginingLoadPageSprite.setTexture(BeginingLoadPage);

    ExpectationToStartTheGameTextue.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/427810.jpg");
    ExpToStTheGameTexSprite.setTexture(ExpectationToStartTheGameTextue);

    ArrangeTeamsOption.setFont(GameFont);
    ArrangeTeamsOption.setString("ArrangeTeames");
    ArrangeTeamsOption.setCharacterSize(50);
    ArrangeTeamsOption.setColor(Color::White);
    ArrangeTeamsOption.setPosition(0,0);

    BackOption.setFont(GameFont);
    BackOption.setString("Back");
    BackOption.setCharacterSize(50);
    BackOption.setColor(Color::White);
    BackOption.setPosition(0,50);

    NextPlayerOption.setFont(GameFont);
    NextPlayerOption.setString("Next playe");
    NextPlayerOption.setCharacterSize(50);
    NextPlayerOption.setColor(Color::White);
    NextPlayerOption.setPosition(1450,0);

    GoToGameOption.setFont(GameFont);
    GoToGameOption.setString("GO TO GAME ...");
    GoToGameOption.setCharacterSize(50);
    GoToGameOption.setColor(Color::White);
    GoToGameOption.setPosition(1400,0);

    Loading.setFont(GameFont);
    Loading.setString("Loading . . . ");
    Loading.setCharacterSize(100);
    Loading.setColor(Color::White);
    Loading.setPosition(VideoMode::getDesktopMode().width/3,VideoMode::getDesktopMode().height/2 -50);

    BattleOfBasu.setFont(GameFont);
    BattleOfBasu.setString("BATTLE OF HEROES");
    BattleOfBasu.setCharacterSize(90);
    BattleOfBasu.setColor(Color::Red);
    BattleOfBasu.setPosition(VideoMode::getDesktopMode().width/4 -100,VideoMode::getDesktopMode().height/2 -50);

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


