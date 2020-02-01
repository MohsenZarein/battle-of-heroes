#include "menu.h"
#include <iostream>
#include <chrono>

using namespace sf;

Menu::Menu()
{
    window = new RenderWindow(sf::VideoMode(1920,1080),"Battle of Basu",Style::Fullscreen);

    ShutgunBuffer.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/sounds/shotgun.wav");
    Shutgun.setBuffer(ShutgunBuffer);
    Shutgun.setLoop(false);

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
    option4.setPosition((1920/3)+150,300);

}


void Menu::exec()
{
    Event event;
    state currentState = MENU;
    Heroes HeroName = None;
    int WhichPlayerWon = -1;

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
              static short int MaximumNumberofHerosP1 = 5;
              for(int i=0 ; i<gridPlayer1->getRow() ; i++) {
                  for(int j=0 ; j<gridPlayer1->getCol() ; j++) {
                      if(gridPlayer1->gridArr[i][j].getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                              event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                          switch (HeroName) {
                          case MrsGhost_Selected:
                              if(player1->mrsghost->isSelected()) {
                                  HeroName = None;
                                  break;
                              }
                              player1->mrsghost->set_position_on_grid(Vector2i(i,j));
                              player1->mrsghost->Selected = true;
                              MaximumNumberofHerosP1--;
                              player1->SetHero(player1->mrsghost);
                              break;
                          case Robi_Selected:
                              if(player1->robi->isSelected()) {
                                  HeroName = None;
                                  break;
                              }
                              player1->robi->set_position_on_grid(Vector2i(i,j));
                              player1->robi->Selected = true;
                              MaximumNumberofHerosP1--;
                              player1->SetHero(player1->robi);
                              break;
                          case Leon_Selected:
                              if(player1->leon->isSelected()) {
                                  HeroName = None;
                                  break;
                              }
                              player1->leon->set_position_on_grid(Vector2i(i,j));
                              player1->leon->Selected = true;
                              MaximumNumberofHerosP1--;
                              player1->SetHero(player1->leon);
                              break;
                          case DrMarry_Selected:
                              if(player1->drmarry->isSelected()) {
                                  HeroName = None;
                                  break;
                              }
                              player1->drmarry->set_position_on_grid(Vector2i(i,j));
                              player1->drmarry->Selected = true;
                              MaximumNumberofHerosP1--;
                              player1->SetHero(player1->drmarry);
                              break;
                          case Snipper_Selected:
                              if(player1->snipper->isSelected()) {
                                  HeroName = None;
                                  break;
                              }
                              player1->snipper->set_position_on_grid(Vector2i(i,j));
                              player1->snipper->Selected = true;
                              MaximumNumberofHerosP1--;
                              player1->SetHero(player1->snipper);
                              break;
                          case Kratos_Selected:
                              if(player1->kratos->isSelected()) {
                                  HeroName = None;
                                  break;
                              }
                              player1->kratos->set_position_on_grid(Vector2i(i,j));
                              player1->kratos->Selected = true;
                              MaximumNumberofHerosP1--;
                              player1->SetHero(player1->kratos);
                              break;
                          case Giant_Selected:
                              if(player1->giant->isSelected()) {
                                  HeroName = None;
                                  break;
                              }
                              player1->giant->set_position_on_grid(Vector2i(i,j));
                              player1->giant->Selected = true;
                              MaximumNumberofHerosP1--;
                              player1->SetHero(player1->giant);
                              break;
                           case AlphaMan_Selected:
                              if(player1->alphaman->isSelected()) {
                                  HeroName  = None;
                                  break;
                              }
                              player1->alphaman->set_position_on_grid(Vector2i(i,j));
                              player1->alphaman->Selected = true;
                              MaximumNumberofHerosP1--;
                              player1->SetHero(player1->alphaman);
                              break;
                           case Professor_Selected:
                              if(player1->professor->isSelected()) {
                                  HeroName = None;
                                  break;
                              }
                              player1->professor->set_position_on_grid(Vector2i(i,j));
                              player1->professor->Selected = true;
                              MaximumNumberofHerosP1--;
                              player1->SetHero(player1->professor);
                              break;
                           case Commander_Selected:
                              if(player1->commander->isSelected()) {
                                  HeroName = None;
                                  break;
                              }
                              player1->commander->set_position_on_grid(Vector2i(i,j));
                              player1->commander->Selected = true;
                              MaximumNumberofHerosP1--;
                              player1->SetHero(player1->commander);
                              break;
                          default:
                              break;
                          }
                          if(MaximumNumberofHerosP1 >= 0) {
                              gridPlayer1->setHeroIcon(static_cast<Vector2f>(Mouse::getPosition()),HeroName);
                              HeroName = None;
                          }
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
               static short int MaximumNumberofHerosP2 = 5;
               for(int i=0 ; i<gridPlayer2->getRow() ; i++) {
                   for(int j=0 ; j<gridPlayer2->getCol() ; j++) {
                       if(gridPlayer2->gridArr[i][j].getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                               event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                           switch (HeroName) {
                           case MrsGhost_Selected:
                               if(player2->mrsghost->isSelected()) {
                                   HeroName = None;
                                   break;
                               }
                               player2->mrsghost->set_position_on_grid(Vector2i(i,j));
                               player2->mrsghost->Selected = true;
                               MaximumNumberofHerosP2--;
                               player2->SetHero(player2->mrsghost);
                               break;
                           case Robi_Selected:
                               if(player2->robi->isSelected()) {
                                   HeroName = None;
                                   break;
                               }
                               player2->robi->set_position_on_grid(Vector2i(i,j));
                               player2->robi->Selected = true;
                               MaximumNumberofHerosP2--;
                               player2->SetHero(player2->robi);
                                break;
                           case Leon_Selected:
                               if(player2->leon->isSelected()) {
                                   HeroName = None;
                                   break;
                               }
                               player2->leon->set_position_on_grid(Vector2i(i,j));
                               player2->leon->Selected = true;
                               MaximumNumberofHerosP2--;
                               player2->SetHero(player2->leon);
                               break;
                           case DrMarry_Selected:
                               if(player2->drmarry->isSelected()) {
                                   HeroName = None;
                                   break;
                               }
                               player2->drmarry->set_position_on_grid(Vector2i(i,j));
                               player2->drmarry->Selected = true;
                               MaximumNumberofHerosP2--;
                               player2->SetHero(player2->drmarry);
                               break;
                           case Snipper_Selected:
                               if(player2->snipper->isSelected()) {
                                   HeroName = None;
                                   break;
                               }
                               player2->snipper->set_position_on_grid(Vector2i(i,j));
                               player2->snipper->Selected = true;
                               MaximumNumberofHerosP2--;
                               player2->SetHero(player2->snipper);
                               break;
                           case Kratos_Selected:
                               if(player2->kratos->isSelected()) {
                                   HeroName = None;
                                   break;
                               }
                               player2->kratos->set_position_on_grid(Vector2i(i,j));
                               player2->kratos->Selected = true;
                               MaximumNumberofHerosP2--;
                               player2->SetHero(player2->kratos);

                               break;
                           case Giant_Selected:
                               if(player2->giant->isSelected()) {
                                   HeroName = None;
                                   break;
                               }
                               player2->giant->set_position_on_grid(Vector2i(i,j));
                               player2->giant->Selected = true;
                               MaximumNumberofHerosP2--;
                               player2->SetHero(player2->giant);
                               break;
                           case AlphaMan_Selected:
                               if(player2->alphaman->isSelected()) {
                                   HeroName = None;
                                   break;
                               }
                               player2->alphaman->set_position_on_grid(Vector2i(i,j));
                               player2->alphaman->Selected = true;
                               MaximumNumberofHerosP2--;
                               player2->SetHero(player2->alphaman);
                               break;
                           case Professor_Selected:
                               if(player2->professor->isSelected()) {
                                   HeroName = None;
                                   break;
                               }
                               player2->professor->set_position_on_grid(Vector2i(i,j));
                               player2->professor->Selected = true;
                               MaximumNumberofHerosP2--;
                               player2->SetHero(player2->professor);
                               break;
                           case Commander_Selected:
                               if(player2->commander->isSelected()) {
                                   HeroName = None;
                                   break;
                               }
                               player2->commander->set_position_on_grid(Vector2i(i,j));
                               player2->commander->Selected = true;
                               MaximumNumberofHerosP2--;
                               player2->SetHero(player2->commander);
                               break;
                           default:
                               break;
                           }
                           if(MaximumNumberofHerosP2 >= 0) {
                               gridPlayer2->setHeroIcon(static_cast<Vector2f>(Mouse::getPosition()),HeroName);
                               HeroName = None;
                           }
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
                window->draw(game.getP1ChooseHeroToAttack());
                window->draw(game.Player1txt);
                window->draw(game.Ready);
                window->draw(game.to);
                window->draw(game.Attack);

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

                short int counter1 = 0;
                for(auto const &item : player1->getHero()) {

                       item->card->draw(Vector2f(0.23,0.23),Vector2f((counter1*350)+0,950),item->getHealth());
                       counter1++;
                       if(item->getHealth() < 1) {
                           item->card->getCardTextureSprite().setColor(Color::Red);
                       }

                       if(item->card->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition()))) {
                           item->card->getCardTextureSprite().setColor(Color(0,191,255));
                       }
                       else{
                           item->card->getCardTextureSprite().setColor(Color::White);
                       }
                       if(item->card->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                               event.key.code == Mouse::isButtonPressed(Mouse::Left)) {

                           player1->WhichHeroIsSelected(static_cast<Vector2f>(Mouse::getPosition()),HeroName);

                       }
                }
                short int counter2 = 0;
                for(auto item : player2->getHero()) {
                    item->card->draw(Vector2f(0.25,0.25),Vector2f(750,(counter2*130)+50),item->getHealth());
                    counter2++;
                }

                for(int i=0 ; i<BattleField_P2->getRow() ; i++) {
                    for(int j=0 ; j<BattleField_P2->getCol() ; j++) {
                        if(BattleField_P2->gridArr[i][j].getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                                event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                            switch (HeroName) {
                            case MrsGhost_Selected:
                                for(auto const &item : player1->getHero()) {
                                    if(item->Name == "MrsGhost" && item->getHealth() >=1 ) {
                                        item->Attack(Vector2i(i,j),BattleField_P2,BattleField_P1,player2->getHero());
                                        Shutgun.play();
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case AlphaMan_Selected:
                                for(auto const &item : player1->getHero()) {
                                    if(item->Name == "AlphaMan" && item->getHealth() >= 1) {
                                        item->Attack(Vector2i(i,j),BattleField_P2,BattleField_P1,player2->getHero());
                                        Shutgun.play();
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Commander_Selected:
                                for(auto const &item : player1->getHero()) {
                                    if(item->Name == "Commander" && item->getHealth() >= 1 ) {
                                        Commander* cmd = dynamic_cast<Commander*>(item);
                                        item->Attack(Vector2i(i,j),BattleField_P2,BattleField_P1,player2->getHero());
                                        Shutgun.play();
                                        if(cmd->isFirstAttackDone()) {
                                            HeroName = None;
                                            cmd->setFirstAttack(false);
                                        }
                                        else {
                                            cmd->setFirstAttack(true);
                                        }
                                        break;
                                    }
                                }
                                break;
                             case DrMarry_Selected:
                                for(auto const &item : player1->getHero()) {
                                    if(item->Name == "DrMarry" && item->getHealth() >= 1) {
                                        item->Attack(Vector2i(i,j),BattleField_P2,BattleField_P1,player2->getHero());
                                        Shutgun.play();
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Giant_Selected:
                                for(auto const &item : player1->getHero()) {
                                    if(item->Name == "Giant" && item->getHealth() >= 1) {
                                        if(player1->giant->isDonateActive()) {

                                            Giant* Gnt = dynamic_cast<Giant*>(item);
                                            Gnt->Donate(player1->getHero());
                                            Gnt->setDonateCondition(false);
                                        }
                                        else {
                                            item->Attack(Vector2i(i,j),BattleField_P2,BattleField_P1,player2->getHero());
                                            Shutgun.play();
                                        }
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Leon_Selected:
                                for(auto const &item : player1->getHero()) {
                                    if(item->Name == "Leon" && item->getHealth() >= 1) {
                                        item->Attack(Vector2i(i,j),BattleField_P2,BattleField_P1,player2->getHero());
                                        Shutgun.play();
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Professor_Selected:
                                for(auto const &item : player1->getHero()) {
                                    if(item->Name == "Professor" && item->getHealth() >= 1) {
                                        item->Attack(Vector2i(i,j),BattleField_P2,BattleField_P1,player2->getHero());
                                        Shutgun.play();
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Robi_Selected:
                                for(auto const &item : player1->getHero()) {
                                    if(item->Name == "Robi" && item->getHealth() >= 1) {
                                        item->Attack(Vector2i(i,j),BattleField_P2,BattleField_P1,player2->getHero());
                                        Shutgun.play();
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Snipper_Selected:
                                for(auto const &item : player1->getHero()) {
                                    if(item->Name == "Snipper" && item->getHealth() >=1) {
                                        item->Attack(Vector2i(i,j),BattleField_P2,BattleField_P1,player2->getHero());
                                        Shutgun.play();
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Kratos_Selected:
                                for(auto const &item : player1->getHero()) {
                                    if(item->Name == "Kratos" && item->getHealth() >= 1) {
                                        item->Attack(Vector2i(i,j),BattleField_P2,BattleField_P1,player2->getHero());
                                        Shutgun.play();
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
                WhichPlayerWon =  game.checkWinningState(player1,player2,currentState);

                BattleField_P2->draw();
                window->display();
            }
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if(currentState == Player1_BattleField) {
                window->clear();
                window->draw(game.getGameBackgroundSprite());
                window->draw(game.getNextPlayerOption());
                window->draw(game.getP2ChooseHeroToAttack());
                window->draw(game.Player2txt);
                window->draw(game.Ready);
                window->draw(game.to);
                window->draw(game.Attack);

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

                short int counter1 = 0;
                for(auto const &item : player2->getHero()) {

                        item->card->draw(Vector2f(0.23,0.23),Vector2f((counter1*350)+0,950),item->getHealth());
                        counter1++;
                        if(item->getHealth() < 1) {
                            item->card->getCardTextureSprite().setColor(Color::Red);
                        }
                        if(item->card->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition()))) {
                            item->card->getCardTextureSprite().setColor(Color(0,191,255));
                        }
                        else{
                            item->card->getCardTextureSprite().setColor(Color::White);
                        }

                       if(item->card->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                               event.key.code == Mouse::isButtonPressed(Mouse::Left)) {

                           player2->WhichHeroIsSelected(static_cast<Vector2f>(Mouse::getPosition()),HeroName);

                       }
                }

                short int counter2 = 0;
                for(auto item : player1->getHero()) {
                    item->card->draw(Vector2f(0.25,0.25),Vector2f(750,(counter2*130)+50),item->getHealth());
                    counter2++;
                }

                for(int i=0 ; i<BattleField_P1->getRow() ; i++) {
                    for(int j=0 ; j<BattleField_P1->getCol() ; j++) {
                        if(BattleField_P1->gridArr[i][j].getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                                event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                            switch (HeroName) {
                            case MrsGhost_Selected:
                                for(auto const &item : player2->getHero()) {
                                    if(item->Name == "MrsGhost"  && item->getHealth() >= 1) {
                                        item->Attack(Vector2i(i,j),BattleField_P1,BattleField_P2,player1->getHero());
                                        Shutgun.play();
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case AlphaMan_Selected:
                                for(auto const &item : player2->getHero()) {
                                    if(item->Name == "AlphaMan" && item->getHealth() >= 1) {
                                        item->Attack(Vector2i(i,j),BattleField_P1,BattleField_P2,player1->getHero());
                                        Shutgun.play();
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Commander_Selected:
                                for(auto const &item : player2->getHero()) {
                                    if(item->Name == "Commander" && item->getHealth() >= 1 ) {
                                        Commander* cmd = dynamic_cast<Commander*>(item);
                                        item->Attack(Vector2i(i,j),BattleField_P1,BattleField_P2,player1->getHero());
                                        Shutgun.play();
                                        if(cmd->isFirstAttackDone()) {
                                            HeroName = None;
                                            cmd->setFirstAttack(false);
                                        }
                                        else {
                                            cmd->setFirstAttack(true);
                                        }
                                        break;
                                    }
                                }
                                break;
                            case DrMarry_Selected:
                               for(auto const &item : player2->getHero()) {
                                   if(item->Name == "DrMarry" && item->getHealth() >= 1) {
                                       item->Attack(Vector2i(i,j),BattleField_P1,BattleField_P2,player1->getHero());
                                       Shutgun.play();
                                       break;
                                   }
                               }
                               HeroName = None;
                               break;
                            case Giant_Selected:
                                for(auto const &item : player2->getHero()) {
                                    if(item->Name == "Giant" && item->getHealth() >= 1) {
                                        if(player2->giant->isDonateActive()) {

                                            Giant* Gnt = dynamic_cast<Giant*>(item);
                                            Gnt->Donate(player2->getHero());
                                            Gnt->setDonateCondition(false);
                                        }
                                        else {
                                            item->Attack(Vector2i(i,j),BattleField_P1,BattleField_P2,player1->getHero());
                                            Shutgun.play();
                                        }
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Leon_Selected:
                                for(auto const &item : player2->getHero()) {
                                    if(item->Name == "Leon" && item->getHealth() >= 1) {
                                        item->Attack(Vector2i(i,j),BattleField_P1,BattleField_P2,player1->getHero());
                                        Shutgun.play();
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Professor_Selected:
                                for(auto const &item : player2->getHero()) {
                                    if(item->Name == "Professor" && item->getHealth() >= 1) {
                                        item->Attack(Vector2i(i,j),BattleField_P1,BattleField_P2,player1->getHero());
                                        Shutgun.play();
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Robi_Selected:
                                for(auto const &item : player2->getHero()) {
                                    if(item->Name == "Robi" && item->getHealth() >= 1) {
                                        item->Attack(Vector2i(i,j),BattleField_P1,BattleField_P2,player1->getHero());
                                        Shutgun.play();
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Snipper_Selected:
                                for(auto const &item : player2->getHero()) {
                                    if(item->Name == "Snipper" && item->getHealth() >= 1) {
                                        item->Attack(Vector2i(i,j),BattleField_P1,BattleField_P2,player1->getHero());
                                        Shutgun.play();
                                        break;
                                    }
                                }
                                HeroName = None;
                                break;
                            case Kratos_Selected:
                                for(auto const &item : player2->getHero()) {
                                    if(item->Name == "Kratos" && item->getHealth() >= 1) {
                                        item->Attack(Vector2i(i,j),BattleField_P1,BattleField_P2,player1->getHero());
                                        Shutgun.play();
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
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if(currentState == WinningState) {

                std::chrono::steady_clock::time_point tend = std::chrono::steady_clock::now() + std::chrono::seconds(5);

                while (std::chrono::steady_clock::now() < tend)
                {
                    window->clear();
                    window->draw(game.getWinBackgroundSprite());
                    if(WhichPlayerWon == 1)
                        window->draw(game.getPlayer1Won());
                    else if(WhichPlayerWon == 2)
                        window->draw(game.getPlayer2Won());

                    window->display();
                }
                window->close();

            }
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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


