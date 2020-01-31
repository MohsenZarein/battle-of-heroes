#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "player.h"

class Game
{
public:
    Game();
    int checkWinningState(Player*,Player*,state&);
    sf::Sprite& getGameBackgroundSprite() ;
    sf::Sprite& getBeginingLoadPageTextureSprite();
    sf::Sprite& getExpToStTheGameTexSprite();
    sf::Sprite& getWinBackgroundSprite();
    sf::Text& getArrangeTeamsOption() ;
    sf::Text& getBackOption() ;
    sf::Text& getNextPlayerOption();
    sf::Text& getGoToGameOption();
    sf::Text& getLoading();
    sf::Text& getBattleOfBasu();
    sf::Text& getPlayer1Text();
    sf::Text& getPlayer2Text();
    sf::Text& getP1ChooseHeroToAttack();
    sf::Text& getP2ChooseHeroToAttack();
    sf::Text& getPlayer1Won();
    sf::Text& getPlayer2Won();
    sf::Text Player1txt;
    sf::Text Player2txt;
    sf::Text Ready;
    sf::Text to;
    sf::Text Attack;
private:
    sf::Texture GameBackground;
    sf::Texture PlayerBackground;
    sf::Texture BeginingLoadPage;
    sf::Texture ExpectationToStartTheGameTextue;
    sf::Texture WinBackGround;
    sf::Sprite GameBackgroundSprite;
    sf::Sprite GameSelectGroundSprite;
    sf::Sprite BeginingLoadPageSprite;
    sf::Sprite ExpToStTheGameTexSprite;
    sf::Sprite WinBackGroundSprite;
    sf::Font GameFont;
    sf::Text ArrangeTeamsOption;
    sf::Text BackOption;
    sf::Text NextPlayerOption;
    sf::Text GoToGameOption;
    sf::Text Loading;
    sf::Text BattleOfBasu;
    sf::Text Player1;
    sf::Text Player2;
    sf::Text Player1ChooseHeroToAttack;
    sf::Text Player2ChooseHeroToAttack;
    sf::Text Player1Won;
    sf::Text Player2Won;

};

#endif // GAME_H
