#include "player.h"

using namespace sf;

Player::Player(const std::string PlayerName,RenderWindow* window)
{
    this->PlayerName = PlayerName;
    this->window = window;

   /* Player1_MrsGhost = new MrsGhost(window);
    Player2_MrsGhost = new MrsGhost(window);

    Player1_Robi = new Robi(window);
    Player2_Robi = new Robi(window);

    Player1_Leon = new Leon(window);
    Player2_Leon = new Leon(window);

    Player1_DrMarry = new DrMarry(window);
    Player2_DrMarry = new DrMarry(window);

    Player1_Snipper = new Snipper(window);
    Player2_Snipper = new Snipper(window);

    Player1_Kratos = new Kratos(window);
    Player2_Kratos = new Kratos(window);

    Player1_Giant = new Giant(window);
    Player2_Giant = new Giant(window);

    Player1_AlphaMan = new AlphaMan(window);
    Player2_AlphaMan = new AlphaMan(window);

    Player1_Professor = new Professor(window);
    Player2_Professor = new Professor(window);

    Player1_Commander = new Commander(window);
    Player2_Commander = new Commander(window);
    */

    mrsghost = new MrsGhost(window);
    robi = new Robi(window);
    leon = new Leon(window);
    drmarry = new DrMarry(window);
    snipper = new Snipper(window);
    kratos = new Kratos(window);
    giant = new Giant(window);
    alphaman = new AlphaMan(window);
    professor = new Professor(window);
    commander = new Commander(window);

}


void Player::SetHero(Hero* a_Hero)
{
    HeroesOfPlayer.push_back(a_Hero);
}

std::vector<Hero *> &Player::getHero()
{
    return HeroesOfPlayer;
}

void Player::WhichHeroIsSelected(sf::Vector2f pos,Heroes &HeroName)
{
    if(this->PlayerName == "Player1"){

        if(mrsghost->mrsghostcard.getCardTextureSprite().getGlobalBounds().contains(pos)) {

               HeroName = MrsGhost_Selected;
         }

        if(robi->robicard.getCardTextureSprite().getGlobalBounds().contains(pos)) {

            HeroName = Robi_Selected;
        }

        if(leon->leoncard.getCardTextureSprite().getGlobalBounds().contains(pos)) {

            HeroName = Leon_Selected;
        }
        if(drmarry->drmarrycard.getCardTextureSprite().getGlobalBounds().contains(pos)) {

            HeroName = DrMarry_Selected;
        }
        if(snipper->snippercard.getCardTextureSprite().getGlobalBounds().contains(pos)) {

            HeroName = Snipper_Selected;
        }
        if(kratos->kratoscard.getCardTextureSprite().getGlobalBounds().contains(pos)) {

            HeroName = Kratos_Selected;
        }
        if(giant->giantcard.getCardTextureSprite().getGlobalBounds().contains(pos)) {

            HeroName = Giant_Selected;
        }
        if(alphaman->alphamancard.getCardTextureSprite().getGlobalBounds().contains(pos)) {

            HeroName = AlphaMan_Selected;
        }
        if(professor->professorcard.getCardTextureSprite().getGlobalBounds().contains(pos)) {

            HeroName = Professor_Selected;
        }
        if(commander->commandercard.getCardTextureSprite().getGlobalBounds().contains(pos)) {

            HeroName = Commander_Selected;
        }
    }

   else if (this->PlayerName == "Player2") {

        if(mrsghost-> mrsghostcard.getCardTextureSprite().getGlobalBounds().contains(pos)) {

               HeroName = MrsGhost_Selected;
         }

        if(robi->robicard.getCardTextureSprite().getGlobalBounds().contains(pos)) {

            HeroName = Robi_Selected;
        }

        if(leon->leoncard.getCardTextureSprite().getGlobalBounds().contains(pos)) {

            HeroName = Leon_Selected;
        }
        if(drmarry->drmarrycard.getCardTextureSprite().getGlobalBounds().contains(pos)) {

            HeroName = DrMarry_Selected;
        }
        if(snipper->snippercard.getCardTextureSprite().getGlobalBounds().contains(pos)) {

            HeroName = Snipper_Selected;
        }
        if(kratos->kratoscard.getCardTextureSprite().getGlobalBounds().contains(pos)) {

            HeroName = Kratos_Selected;
        }
        if(giant->giantcard.getCardTextureSprite().getGlobalBounds().contains(pos)) {

            HeroName = Giant_Selected;
        }
        if(alphaman->alphamancard.getCardTextureSprite().getGlobalBounds().contains(pos)) {

            HeroName = AlphaMan_Selected;
        }
        if(professor->professorcard.getCardTextureSprite().getGlobalBounds().contains(pos)) {

            HeroName = Professor_Selected;
        }
        if(commander->commandercard.getCardTextureSprite().getGlobalBounds().contains(pos)) {

            HeroName = Commander_Selected;
        }
    }
}

Player::~Player()
{

   /* delete Player1_MrsGhost;
    delete Player2_MrsGhost;

    delete Player1_Robi;
    delete Player2_Robi;

    delete Player1_Leon;
    delete Player2_Leon;

    delete Player1_DrMarry;
    delete Player2_DrMarry;

    delete Player1_Snipper;
    delete Player2_Snipper;

    delete Player1_Kratos;
    delete Player2_Kratos;

    delete Player1_Giant;
    delete Player2_Giant;

    delete Player1_AlphaMan;
    delete Player2_AlphaMan;

    delete Player1_Professor;
    delete Player2_Professor;

    delete Player1_Commander;
    delete Player2_Commander;
    */

    delete mrsghost;
    delete robi;
    delete leon;
    delete drmarry;
    delete snipper;
    delete kratos;
    delete giant;
    delete alphaman;
    delete professor;
    delete commander;
}
