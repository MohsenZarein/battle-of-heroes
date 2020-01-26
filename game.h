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

};

#endif // GAME_H
