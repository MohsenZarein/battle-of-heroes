#include "menu.h"
#include <iostream>
#include <chrono>
#include <typeinfo>

using namespace sf;

Menu::Menu()
{
    window = new RenderWindow(sf::VideoMode(1920,1080),"Battle of Basu",Style::Fullscreen);

    player1 = new Player("Player1",window);
    player2 = new Player("Player2",window);

    gridPlayer1 = new Grid(9,9,window);
    gridPlayer2 = new Grid(9,9,window);

    BattleField_P1 = new Grid(9,9,window);
    BattleField_P2 = new Grid(9,9,window);

    MenuBackground.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/5048584-banner-battle-lightning-warrior.jpg");
    MenuBackgroundSprite.setTexture(MenuBackground);

    MenuFont.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/Fonts/Lokananta.ttf");

    option1.setFont(MenuFont);
    option1.setString("single player");
    option1.setCharacterSize(80);
    option1.setColor(Color::White);
    option1.setPosition(1920/3,0);

    option2.setFont(MenuFont);
    option2.setString("multi player");
    option2.setCharacterSize(80);
    option2.setColor(Color::White);
    option2.setPosition((1920/3)+50,100);

    option3.setFont(MenuFont);
    option3.setString("credit");
    option3.setCharacterSize(80);
    option3.setColor(Color::White);
    option3.setPosition((1920/3)+100,200);

    option4.setFont(MenuFont);
    option4.setString("quit");
    option4.setCharacterSize(80);
    option4.setColor(Color::White);
    option4.setPosition((1920/3)+150,280);

}


void Menu::exec()
{
    Event event;
    state currentState = MENU;
    Heroes HeroName = None;

    while(window->isOpen()) {

        while(window->pollEvent(event)){
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if(event.type == sf::Event::Closed) {
                window->close();
            }
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if(Keyboard::isKeyPressed(Keyboard::Escape)) {
                window->close();
            }
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if(currentState == Begin) {

                std::chrono::steady_clock::time_point tend = std::chrono::steady_clock::now() + std::chrono::seconds(4);

                while (std::chrono::steady_clock::now() < tend)
                {
                    window->clear();
                    window->draw(game.getBeginingLoadPageTextureSprite());
                    window->draw(game.getBattleOfBasu());
                    window->display();
                }
                currentState = MENU;
                break;
            }
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if(currentState == MENU) {

                if(option2.getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                        event.key.code == Mouse::isButtonPressed(Mouse::Left))
                {
                    currentState = Multipalyer ;

                    window->clear();
                    break;

                }
                if(option4.getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                        event.key.code == Mouse::isButtonPressed(Mouse::Left))
                {
                    window->close();

                }
                if(option4.getGlobalBounds().contains(static_cast<Vector2f> (Mouse::getPosition()))) {
                    option4.setColor(sf::Color::Magenta);
                }
                else {
                    option4.setColor(sf::Color::White);
                }
                if(option3.getGlobalBounds().contains(static_cast<Vector2f> (Mouse::getPosition()))) {
                    option3.setColor(sf::Color::Magenta);
                }
                else {
                    option3.setColor(sf::Color::White);
                }
                if(option2.getGlobalBounds().contains(static_cast<Vector2f> (Mouse::getPosition()))) {
                    option2.setColor(sf::Color::Magenta);
                }
                else {
                    option2.setColor(sf::Color::White);
                }
                if(option1.getGlobalBounds().contains(static_cast<Vector2f> (Mouse::getPosition()))) {
                    option1.setColor(sf::Color::Magenta);
                }
                else {
                    option1.setColor(sf::Color::White);
                }
                window->clear();
                window->draw(MenuBackgroundSprite);
                window->draw(option1);
                window->draw(option2);
                window->draw(option3);
                window->draw(option4);
                window->display();
            }
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if(currentState == Multipalyer) {
              if(game.getArrangeTeamsOption().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition()))){
                  game.getArrangeTeamsOption().setColor(Color::Magenta);
              }
              else{
                  game.getArrangeTeamsOption().setColor(Color::White);
              }
              if(game.getBackOption().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition()))){
                  game.getBackOption().setColor(Color::Magenta);
              }
              else{
                  game.getBackOption().setColor(Color::White);
              }
              if(game.getBackOption().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                      event.key.code == Mouse::isButtonPressed(Mouse::Left)){
                  currentState = MENU;
                  break;
              }
              if(game.getArrangeTeamsOption().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                      event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                  currentState = Player1_ArrangeTeam;
                  break;
              }

              window->clear();
              window->draw(game.getGameBackgroundSprite());
              window->draw(game.getArrangeTeamsOption());
              window->draw(game.getBackOption());
              window->display();

             }
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if(currentState == Player1_ArrangeTeam) {

              window->clear();
              window->draw(game.getGameBackgroundSprite());
              window->draw(game.getNextPlayerOption());
              window->draw(game.getPlayer1Text());

              if(game.getNextPlayerOption().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition()))){
                  game.getNextPlayerOption().setColor(Color::Magenta);
              }
              else{
                  game.getNextPlayerOption().setColor(Color::White);
              }
              if(game.getNextPlayerOption().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                      event.key.code == Mouse::isButtonPressed(Mouse::Left)){
                  currentState = Player2_ArrangeTeam;
                  HeroName = None;
                  break;
              }
              if(event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                  player1->WhichHeroIsSelected(static_cast<Vector2f>(Mouse::getPosition()),HeroName);
              }

              for(int i=0 ; i<gridPlayer1->getRow() ; i++) {
                  for(int j=0 ; j<gridPlayer1->getCol() ; j++) {
                      if(gridPlayer1->gridArr[i][j].getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                              event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                          switch (HeroName) {
                          case MrsGhost_Selected:
                              player1->mrsghost->set_position_on_grid(Vector2i(i,j));
                              player1->SetHero(player1->mrsghost);
                              break;
                          case Robi_Selected:
                              player1->robi->set_position_on_grid(Vector2i(i,j));
                              player1->SetHero(player1->robi);
                               break;
                          case Leon_Selected:
                              player1->leon->set_position_on_grid(Vector2i(i,j));
                              player1->SetHero(player1->leon);
                              break;
                          case DrMarry_Selected:
                              player1->drmarry->set_position_on_grid(Vector2i(i,j));
                              player1->SetHero(player1->drmarry);
                              break;
                          case Snipper_Selected:
                              player1->snipper->set_position_on_grid(Vector2i(i,j));
                              player1->SetHero(player1->snipper);
                              break;
                          case Kratos_Selected:
                              player1->kratos->set_position_on_grid(Vector2i(i,j));
                              player1->SetHero(player1->kratos);
                              break;
                          case Giant_Selected:
                              player1->giant->set_position_on_grid(Vector2i(i,j));
                              player1->SetHero(player1->giant);
                              break;
                           case AlphaMan_Selected:
                              player1->alphaman->set_position_on_grid(Vector2i(i,j));
                              player1->SetHero(player1->alphaman);
                              break;
                           case Professor_Selected:
                              player1->professor->set_position_on_grid(Vector2i(i,j));
                              player1->SetHero(player1->professor);
                              break;
                           case Commander_Selected:
                              player1->commander->set_position_on_grid(Vector2i(i,j));
                              player1->SetHero(player1->commander);
                              break;
                          default:
                              break;
                          }
                          //std::cout<<Player2_MrsGhost.get_position_on_grid().x<<std::endl;
                          //std::cout<<player1->getHero().size()<<std::endl;
                          //std::cout<<player1->getHero().at(0)->get_position_on_grid().x<<std::endl;
                          gridPlayer1->setHeroIcon(static_cast<Vector2f>(Mouse::getPosition()),HeroName);
                          HeroName = None;
                          gridPlayer1->draw();
                          break;
                      }
                  }
              }

               gridPlayer1->draw();
               player1->robi->robicard.draw();
               player1->mrsghost->mrsghostcard.draw();
               player1->leon->leoncard.draw();
               player1->drmarry->drmarrycard.draw();
               player1->snipper->snippercard.draw();
               player1->kratos->kratoscard.draw();
               player1->giant->giantcard.draw();
               player1->alphaman->alphamancard.draw();
               player1->professor->professorcard.draw();
               player1->commander->commandercard.draw();
               window->display();

             }
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if(currentState == Player2_ArrangeTeam) {

                window->clear();
                window->draw(game.getGameBackgroundSprite());
                window->draw(game.getGoToGameOption());
                window->draw(game.getPlayer2Text());

                 if(game.getGoToGameOption().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition()))){
                     game.getGoToGameOption().setColor(Color::Magenta);
                 }
                 else{
                     game.getGoToGameOption().setColor(Color::White);
                 }
                 if(game.getGoToGameOption().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                         event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                     currentState = LoadingPage;
                 }
                 if(event.key.code == Mouse::isButtonPressed(Mouse::Left)) {

                     player2->WhichHeroIsSelected(static_cast<Vector2f>(Mouse::getPosition()),HeroName);
                 }

               for(int i=0 ; i<gridPlayer2->getRow() ; i++) {
                   for(int j=0 ; j<gridPlayer2->getCol() ; j++) {
                       if(gridPlayer2->gridArr[i][j].getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                               event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                           switch (HeroName) {
                           case MrsGhost_Selected:
                               player2->mrsghost->set_position_on_grid(Vector2i(i,j));
                               player2->SetHero(player2->mrsghost);
                               break;
                           case Robi_Selected:
                               player2->robi->set_position_on_grid(Vector2i(i,j));
                               player2->SetHero(player2->robi);
                                break;
                           case Leon_Selected:
                               player2->leon->set_position_on_grid(Vector2i(i,j));
                               player2->SetHero(player2->leon);
                               break;
                           case DrMarry_Selected:
                               player2->drmarry->set_position_on_grid(Vector2i(i,j));
                               player2->SetHero(player2->drmarry);
                               break;
                           case Snipper_Selected:
                               player2->snipper->set_position_on_grid(Vector2i(i,j));
                               player2->SetHero(player2->snipper);
                               break;
                           case Kratos_Selected:
                               player2->kratos->set_position_on_grid(Vector2i(i,j));
                               player2->SetHero(player2->kratos);

                               break;
                           case Giant_Selected:
                               player2->giant->set_position_on_grid(Vector2i(i,j));
                               player2->SetHero(player2->giant);
                               break;
                           case AlphaMan_Selected:
                               player2->alphaman->set_position_on_grid(Vector2i(i,j));
                               player2->SetHero(player2->alphaman);
                               break;
                           case Professor_Selected:
                               player2->professor->set_position_on_grid(Vector2i(i,j));
                               player2->SetHero(player2->professor);
                               break;
                           case Commander_Selected:
                               player2->commander->set_position_on_grid(Vector2i(i,j));
                               player2->SetHero(player2->commander);
                               break;
                           default:
                               break;
                           }
                           //std::cout<<Player2_MrsGhost.get_position_on_grid().x<<std::endl;
                           //std::cout<<player2->getHero().size()<<std::endl;
                           //std::cout<<player2->getHero().back()->get_position_on_grid().x<<std::endl;
                           gridPlayer2->setHeroIcon(static_cast<Vector2f>(Mouse::getPosition()),HeroName);
                           std::cout<<player2->getHero().size()<<std::endl;
                           HeroName = None;
                           gridPlayer2->draw();
                           break;
                       }
                   }
               }

                gridPlayer2->draw();
                player2->robi->robicard.draw();
                player2->mrsghost->mrsghostcard.draw();
                player2->leon->leoncard.draw();
                player2->drmarry->drmarrycard.draw();
                player2->snipper->snippercard.draw();
                player2->kratos->kratoscard.draw();
                player2->giant->giantcard.draw();
                player2->alphaman->alphamancard.draw();
                player2->professor->professorcard.draw();
                player2->commander->commandercard.draw();
                window->display();

            }
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if(currentState == LoadingPage) {

                std::chrono::steady_clock::time_point tend = std::chrono::steady_clock::now() + std::chrono::seconds(5);

                while (std::chrono::steady_clock::now() < tend)
                {
                    window->clear();
                    window->draw(game.getExpToStTheGameTexSprite());
                    window->draw(game.getLoading());
                    window->display();
                }
                currentState = Player2_BattleField;
                break;
            }
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if(currentState == Player2_BattleField) {
                window->clear();
                window->draw(game.getGameBackgroundSprite());
                window->draw(game.getNextPlayerOption());

                if(game.getNextPlayerOption().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition()))) {
                    game.getNextPlayerOption().setFillColor(Color::Magenta);
                }
                else {
                    game.getNextPlayerOption().setFillColor(Color::White);
                }

                if(game.getNextPlayerOption().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                        event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                    currentState = Player1_BattleField;
                    break;
                }

                for(auto const &item : player1->getHero()) {

                       item->card->draw();

                       if(item->card->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                               event.key.code == Mouse::isButtonPressed(Mouse::Left)) {

                           player1->WhichHeroIsSelected(static_cast<Vector2f>(Mouse::getPosition()),HeroName);

                       }
                }
                short int counter = 0;
                for(auto item : player2->getHero()) {
                    item->card->draw(Vector2f(0.25,0.25),Vector2f(750,(counter*130)+50),item->getHealth());
                    counter++;
                }

                for(int i=0 ; i<BattleField_P2->getRow() ; i++) {
                    for(int j=0 ; j<BattleField_P2->getCol() ; j++) {
                        if(BattleField_P2->gridArr[i][j].getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                                event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                            switch (HeroName) {
                            case MrsGhost_Selected:
                                for(auto const &item : player1->getHero()) {
                                    if(item->Name == "MrsGhost") {
                                        item->Attack(Vector2i(i,j),BattleField_P2,BattleField_P1,player2->getHero());
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case AlphaMan_Selected:
                                for(auto const &item : player1->getHero()) {
                                    if(item->Name == "AlphaMan") {
                                        item->Attack(Vector2i(i,j),BattleField_P2,BattleField_P1,player2->getHero());
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Commander_Selected:
                                for(auto const &item : player1->getHero()) {
                                    if(item->Name == "Commander") {
                                        item->Attack(Vector2i(i,j),BattleField_P2,BattleField_P1,player2->getHero());
                                        break;
                                    }
                                }
                                if(player1->commander->isSecondAttackDone()) {
                                    HeroName = None;
                                    player1->commander->setSecondAttack(false);
                                }
                                else{
                                    player1->commander->setSecondAttack(true);
                                }
                                break;
                             case DrMarry_Selected:
                                for(auto const &item : player1->getHero()) {
                                    if(item->Name == "DrMarry") {
                                        item->Attack(Vector2i(i,j),BattleField_P2,BattleField_P1,player2->getHero());
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Giant_Selected:
                                for(auto const &item : player1->getHero()) {
                                    if(item->Name == "Giant") {
                                        if(player1->giant->isDonateActive()) {

                                            Giant* Gnt = dynamic_cast<Giant*>(item);
                                            Gnt->Donate(player1->getHero());
                                            Gnt->setDonateCondition(false);
                                        }
                                        else {
                                            item->Attack(Vector2i(i,j),BattleField_P2,BattleField_P1,player2->getHero());
                                        }
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Leon_Selected:
                                for(auto const &item : player1->getHero()) {
                                    if(item->Name == "Leon") {
                                        item->Attack(Vector2i(i,j),BattleField_P2,BattleField_P1,player2->getHero());
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Professor_Selected:
                                for(auto const &item : player1->getHero()) {
                                    if(item->Name == "Professor") {
                                        item->Attack(Vector2i(i,j),BattleField_P2,BattleField_P1,player2->getHero());
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Robi_Selected:
                                for(auto const &item : player1->getHero()) {
                                    if(item->Name == "Robi") {
                                        item->Attack(Vector2i(i,j),BattleField_P2,BattleField_P1,player2->getHero());
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Snipper_Selected:
                                for(auto const &item : player1->getHero()) {
                                    if(item->Name == "Snipper") {
                                        item->Attack(Vector2i(i,j),BattleField_P2,BattleField_P1,player2->getHero());
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            default:
                                break;
                            }
                        }
                    }
                }

                BattleField_P2->draw();
                window->display();
            }
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if(currentState == Player1_BattleField) {
                window->clear();
                window->draw(game.getGameBackgroundSprite());
                window->draw(game.getNextPlayerOption());

                if(game.getNextPlayerOption().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition()))) {
                    game.getNextPlayerOption().setFillColor(Color::Magenta);
                }
                else {
                    game.getNextPlayerOption().setFillColor(Color::White);
                }

                if(game.getNextPlayerOption().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                        event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                    currentState = Player2_BattleField;
                    break;
                }

                for(auto const &item : player2->getHero()) {

                       item->card->draw();

                       if(item->card->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                               event.key.code == Mouse::isButtonPressed(Mouse::Left)) {

                           player2->WhichHeroIsSelected(static_cast<Vector2f>(Mouse::getPosition()),HeroName);

                       }
                }

                short int counter = 0;
                for(auto item : player1->getHero()) {
                    item->card->draw(Vector2f(0.25,0.25),Vector2f(750,(counter*130)+50),item->getHealth());
                    counter++;
                }

                for(int i=0 ; i<BattleField_P1->getRow() ; i++) {
                    for(int j=0 ; j<BattleField_P1->getCol() ; j++) {
                        if(BattleField_P1->gridArr[i][j].getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                                event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                            switch (HeroName) {
                            case MrsGhost_Selected:
                                for(auto const &item : player2->getHero()) {
                                    if(item->Name == "MrsGhost") {
                                        item->Attack(Vector2i(i,j),BattleField_P1,BattleField_P2,player1->getHero());
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case AlphaMan_Selected:
                                for(auto const &item : player2->getHero()) {
                                    if(item->Name == "AlphaMan") {
                                        item->Attack(Vector2i(i,j),BattleField_P1,BattleField_P2,player1->getHero());
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Commander_Selected:
                                for(auto const &item : player2->getHero()) {
                                    if(item->Name == "Commander") {
                                        item->Attack(Vector2i(i,j),BattleField_P1,BattleField_P2,player1->getHero());
                                        break;
                                    }
                                }
                                if(player2->commander->isSecondAttackDone()) {
                                    HeroName = None;
                                    player2->commander->setSecondAttack(false);
                                }
                                else{
                                    player2->commander->setSecondAttack(true);
                                }
                                break;
                            case DrMarry_Selected:
                               for(auto const &item : player2->getHero()) {
                                   if(item->Name == "DrMarry") {
                                       item->Attack(Vector2i(i,j),BattleField_P1,BattleField_P2,player1->getHero());
                                       break;
                                   }
                               }
                               HeroName = None;
                               break;
                            case Giant_Selected:
                                for(auto const &item : player2->getHero()) {
                                    if(item->Name == "Giant") {
                                        if(player2->giant->isDonateActive()) {

                                            Giant* Gnt = dynamic_cast<Giant*>(item);
                                            Gnt->Donate(player2->getHero());
                                            Gnt->setDonateCondition(false);
                                        }
                                        else {
                                            item->Attack(Vector2i(i,j),BattleField_P1,BattleField_P2,player1->getHero());
                                        }
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Leon_Selected:
                                for(auto const &item : player2->getHero()) {
                                    if(item->Name == "Leon") {
                                        item->Attack(Vector2i(i,j),BattleField_P1,BattleField_P2,player1->getHero());
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Professor_Selected:
                                for(auto const &item : player2->getHero()) {
                                    if(item->Name == "Professor") {
                                        item->Attack(Vector2i(i,j),BattleField_P1,BattleField_P2,player1->getHero());
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Robi_Selected:
                                for(auto const &item : player2->getHero()) {
                                    if(item->Name == "Robi") {
                                        item->Attack(Vector2i(i,j),BattleField_P1,BattleField_P2,player1->getHero());
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Snipper_Selected:
                                for(auto const &item : player2->getHero()) {
                                    if(item->Name == "Snipper") {
                                        item->Attack(Vector2i(i,j),BattleField_P1,BattleField_P2,player1->getHero());
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            default:
                                break;
                            }
                        }
                    }
                }

                BattleField_P1->draw();
                window->display();
            }
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        }
    }
}

Menu::~Menu()
{
    delete window;

    delete player1;
    delete player2;

    delete gridPlayer1;
    delete gridPlayer2;
    delete BattleField_P1;
    delete BattleField_P2;
}


