#include "menu.h"
#include <iostream>
#include <chrono>

using namespace sf;

Menu::Menu()
{
    window = new RenderWindow(sf::VideoMode(1920,1080),"Battle of Basu",Style::Fullscreen);

    Player1_MrsGhost = new MrsGhost();
    Player2_MrsGhost = new MrsGhost();

    Player1_Robi = new Robi();
    Player2_Robi = new Robi();

    Player1_Leon = new Leon();
    Player2_Leon = new Leon();

    Player1_DrMarry = new DrMarry();
    Player2_DrMarry = new DrMarry();

    Player1_Snipper = new Snipper();
    Player2_Snipper = new Snipper();

    Player1_Kratos = new Kratos();
    Player2_Kratos = new Kratos();

    Player1_Giant = new Giant();
    Player2_Giant = new Giant();

    Player1_AlphaMan = new AlphaMan();
    Player2_AlphaMan = new AlphaMan();

    Player1_Commander = new Commander();
    Player2_Commander = new Commander();

    gridPlayer1 = new Grid(9,9,window);
    gridPlayer2 = new Grid(9,9,window);

    BattleField_P1 = new Grid(9,9,window);
    BattleField_P2 = new Grid(9,9,window);

    MenuBackground.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/5048584-banner-battle-lightning-warrior.jpg");
    MenuBackgroundSprite.setTexture(MenuBackground);

    MenuFont.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/Fonts/TarrgetLaserRegular-4OE9.otf");

    option1.setFont(MenuFont);
    option1.setString("single player");
    option1.setCharacterSize(50);
    option1.setColor(Color::White);
    option1.setPosition(1920/3,0);

    option2.setFont(MenuFont);
    option2.setString("multi plyer");
    option2.setCharacterSize(50);
    option2.setColor(Color::White);
    option2.setPosition((1920/3)+50,50);

    option3.setFont(MenuFont);
    option3.setString("credit");
    option3.setCharacterSize(50);
    option3.setColor(Color::White);
    option3.setPosition((1920/3)+100,100);

    option4.setFont(MenuFont);
    option4.setString("quit");
    option4.setCharacterSize(50);
    option4.setColor(Color::White);
    option4.setPosition((1920/3)+150,150);

}


void Menu::exec()
{
    Event event;
    state currentState = Begin;
    Heroes HeroName = None;

    mrsghostcard = new MrsGhostCard(window);
    robicard = new RobiCard(window);
    leoncard = new LeonCard(window);
    drmarrycard = new DrMarryCard(window);
    snippercard = new SnipperCard(window);
    kratoscard = new KratosCard(window);
    giantcard = new GiantCard(window);
    alphamancard = new AlphaManCard(window);
    professorcard  = new ProfessorCard(window);
    commandercard = new CommanderCard(window);

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

              if(game.getNextPlayerOption().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition()))){
                  game.getNextPlayerOption().setColor(Color::Magenta);
              }
              else{
                  game.getNextPlayerOption().setColor(Color::White);
              }
              if(game.getNextPlayerOption().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                      event.key.code == Mouse::isButtonPressed(Mouse::Left)){
                  currentState = Player2_ArrangeTeam;
                  break;
              }

              if(mrsghostcard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                       event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                     HeroName = MrsGhost_Selected;
               }

              if(robicard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                      event.key.code == Mouse::isButtonPressed((Mouse::Left))) {
                  HeroName = Robi_Selected;
              }

              if(leoncard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                      event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                  HeroName = Leon_Selected;
              }
              if(drmarrycard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                      event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                  HeroName = DrMarry_Selected;
              }
              if(snippercard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                      event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                  HeroName = Snipper_Selected;
              }
              if(kratoscard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                      event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                  HeroName = Kratos_Selected;
              }
              if(giantcard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                      event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                  HeroName = Giant_Selected;
              }
              if(alphamancard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                      event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                  HeroName = AlphaMan_Selected;
              }
              if(professorcard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition()))&&
                      event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                  HeroName = Professor_Selected;
              }
              if(commandercard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition()))&&
                      event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                  HeroName = Commander_Selected;
              }
              for(int i=0 ; i<gridPlayer1->getRow() ; i++) {
                  for(int j=0 ; j<gridPlayer1->getCol() ; j++) {
                      if(gridPlayer1->gridArr[i][j].getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                              event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                          switch (HeroName) {
                          case MrsGhost_Selected:
                              //std::cout<<player1.HeroesOfPlayer.size()<<std::endl;
                              Player1_MrsGhost->set_position_on_grid(Vector2i(i,j));
                              player1.SetHero(Player1_MrsGhost);
                              //std::cout<<player1.HeroesOfPlayer.size();
                              break;
                          case Robi_Selected:
                              Player1_Robi->set_position_on_grid(Vector2i(i,j));
                              player1.SetHero(Player1_Robi);
                               break;
                          case Leon_Selected:
                              Player1_Leon->set_position_on_grid(Vector2i(i,j));
                              player1.SetHero(Player1_Leon);
                              break;
                          case DrMarry_Selected:
                              Player1_DrMarry->set_position_on_grid(Vector2i(i,j));
                              player1.SetHero(Player1_DrMarry);
                              break;
                          case Snipper_Selected:
                              Player1_Snipper->set_position_on_grid(Vector2i(i,j));
                              player1.SetHero(Player1_Snipper);
                              break;
                          case Kratos_Selected:
                              Player1_Kratos->set_position_on_grid(Vector2i(i,j));
                              player1.SetHero(Player1_Kratos);
                              break;
                          case Giant_Selected:
                              Player1_Giant->set_position_on_grid(Vector2i(i,j));
                              player1.SetHero(Player1_Giant);
                              break;
                           case AlphaMan_Selected:
                              Player1_AlphaMan->set_position_on_grid(Vector2i(i,j));
                              player1.SetHero(Player1_AlphaMan);
                              break;
                           case Professor_Selected:
                              Player1_Professor->set_position_on_grid(Vector2i(i,j));
                              player1.SetHero(Player1_Professor);
                              break;
                           case Commander_Selected:
                              Player1_Commander->set_position_on_grid(Vector2i(i,j));
                              player1.SetHero(Player1_Commander);
                              break;
                          default:
                              break;
                          }
                          //std::cout<<Player2_MrsGhost.get_position_on_grid().x<<std::endl;
                          gridPlayer1->setHeroIcon(static_cast<Vector2f>(Mouse::getPosition()),HeroName);
                          gridPlayer1->draw();
                          break;
                      }
                  }
              }

               gridPlayer1->draw();
               robicard->draw();
               mrsghostcard->draw();
               leoncard->draw();
               drmarrycard->draw();
               snippercard->draw();
               kratoscard->draw();
               giantcard->draw();
               alphamancard->draw();
               professorcard->draw();
               commandercard->draw();
               window->display();

             }
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if(currentState == Player2_ArrangeTeam) {

                window->clear();
                window->draw(game.getGameBackgroundSprite());
                window->draw(game.getGoToGameOption());

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

               /* if (mrsghostcard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition()))) {
                    mrsghostcard->getCardTextureSprite().setColor(Color::Magenta);
                      //mrsghostcard->draw();
                }*/


               if(mrsghostcard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                        event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                      HeroName = MrsGhost_Selected;
                }

               if(robicard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                       event.key.code == Mouse::isButtonPressed((Mouse::Left))) {
                   HeroName = Robi_Selected;
               }

               if(leoncard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                       event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                   HeroName = Leon_Selected;
               }
               if(drmarrycard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                       event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                   HeroName = DrMarry_Selected;
               }
               if(snippercard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                       event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                   HeroName = Snipper_Selected;
               }
               if(kratoscard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                       event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                   HeroName = Kratos_Selected;
               }
               if(giantcard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                       event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                   HeroName = Giant_Selected;
               }
               if(alphamancard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                       event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                   HeroName = AlphaMan_Selected;
               }
               if(professorcard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition()))&&
                       event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                   HeroName = Professor_Selected;
               }
               if(commandercard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition()))&&
                       event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                   HeroName = Commander_Selected;
               }
               for(int i=0 ; i<gridPlayer2->getRow() ; i++) {
                   for(int j=0 ; j<gridPlayer2->getCol() ; j++) {
                       if(gridPlayer2->gridArr[i][j].getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                               event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                           switch (HeroName) {
                           case MrsGhost_Selected:
                               Player2_MrsGhost->set_position_on_grid(Vector2i(i,j));
                               player2.SetHero(Player2_MrsGhost);
                               break;
                           case Robi_Selected:
                               Player2_Robi->set_position_on_grid(Vector2i(i,j));
                               player2.SetHero(Player2_Robi);
                                break;
                           case Leon_Selected:
                               Player2_Leon->set_position_on_grid(Vector2i(i,j));
                               player2.SetHero(Player2_Leon);
                               break;
                           case DrMarry_Selected:
                               Player2_DrMarry->set_position_on_grid(Vector2i(i,j));
                               player2.SetHero(Player2_DrMarry);
                               break;
                           case Snipper_Selected:
                               Player2_Snipper->set_position_on_grid(Vector2i(i,j));
                               player2.SetHero(Player2_Snipper);
                               break;
                           case Kratos_Selected:
                               Player2_Kratos->set_position_on_grid(Vector2i(i,j));
                               player2.SetHero(Player2_Kratos);
                               break;
                           case Giant_Selected:
                               Player2_Giant->set_position_on_grid(Vector2i(i,j));
                               player2.SetHero(Player2_Giant);
                               break;
                           case AlphaMan_Selected:
                               Player2_AlphaMan->set_position_on_grid(Vector2i(i,j));
                               player2.SetHero(Player2_AlphaMan);
                               break;
                           case Professor_Selected:
                               Player2_Professor->set_position_on_grid(Vector2i(i,j));
                               player2.SetHero(Player2_Professor);
                               break;
                           case Commander_Selected:
                               Player2_Commander->set_position_on_grid(Vector2i(i,j));
                               player2.SetHero(Player2_Commander);
                               break;
                           default:
                               break;
                           }
                           //std::cout<<Player2_MrsGhost.get_position_on_grid().x<<std::endl;
                           gridPlayer2->setHeroIcon(static_cast<Vector2f>(Mouse::getPosition()),HeroName);
                           gridPlayer2->draw();
                           break;
                       }
                   }
               }

                gridPlayer2->draw();
                robicard->draw();
                mrsghostcard->draw();
                leoncard->draw();
                drmarrycard->draw();
                snippercard->draw();
                kratoscard->draw();
                giantcard->draw();
                alphamancard->draw();
                professorcard->draw();
                commandercard->draw();
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

                if(mrsghostcard->getCardTextureSprite().getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                        event.key.code == Mouse::isButtonPressed(Mouse::Left)){
                    HeroName = MrsGhost_Selected;
                }
                for(int i=0 ; i<BattleField_P2->getRow() ; i++) {
                    for(int j=0 ; j<BattleField_P2->getCol() ; j++) {
                        if(BattleField_P2->gridArr[i][j].getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition())) &&
                                event.key.code == Mouse::isButtonPressed(Mouse::Left)) {
                            switch (HeroName) {
                            case MrsGhost_Selected:
                                BattleField_P2->gridArr[i][j].setFillColor(Color::Yellow);
                                break;
                            default:
                                break;
                            }
                        }
                    }
                }

                mrsghostcard->draw();
                BattleField_P2->draw();
                window->display();
            }
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        }
    }
}

Menu::~Menu()
{
    delete window;

    delete gridPlayer1;
    delete gridPlayer2;

    delete mrsghostcard;
    delete robicard;
    delete leoncard;
    delete drmarrycard;
    delete snippercard;
    delete kratoscard;
    delete giantcard;
    delete alphamancard;
    delete professorcard;
    delete commandercard;

    delete Player1_MrsGhost;
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
}


