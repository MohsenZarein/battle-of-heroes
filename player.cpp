#include "player.h"

using namespace sf;

Player::Player(const std::string PlayerName,RenderWindow* window)
{
    this->PlayerName = PlayerName;
    this->window = window;

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
