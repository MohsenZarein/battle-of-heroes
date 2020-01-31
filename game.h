#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    sf::Sprite& getGameBackgroundSprite() ;
    sf::Text& getArrangeTeamsOption() ;
    sf::Text& getBackOption() ;
    sf::Text& getNextPlayerOption();
    sf::Text& getGoToGameOption();
    sf::Sprite& getBeginingLoadPageTextureSprite();
    sf::Text& getLoading();
    sf::Sprite& getExpToStTheGameTexSprite();
    sf::Text& getBattleOfBasu();
    sf::Text& getPlayer1Text();
    sf::Text& getPlayer2Text();
    sf::Text& getP1ChooseHeroToAttack();
    sf::Text& getP2ChooseHeroToAttack();
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
    sf::Sprite GameBackgroundSprite;
    sf::Sprite GameSelectGroundSprite;
    sf::Sprite BeginingLoadPageSprite;
    sf::Sprite ExpToStTheGameTexSprite;
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

};

#endif // GAME_H
