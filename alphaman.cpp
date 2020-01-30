#include "alphaman.h"
#include "mrsghost.h"
#include "iostream"
using namespace sf;

AlphaMan::AlphaMan(sf::RenderWindow* window) : alphamancard(window)
{
    Name = "AlphaMan";
    this->window = window;
    health = 13;
    power = 2;
    card = &alphamancard;
}

AlphaMan::~AlphaMan() {}

void AlphaMan::Attack(Vector2i goal , Grid* OpponentGrid , Grid* ThisGrid, std::vector<Hero*> &OpponentHeroes)
{
    for(int i=0 ; i<OpponentGrid->getRow() ; i++) {
        for(int j=0 ; j<OpponentGrid->getCol() ; j++) {
            if(i==goal.x && j==goal.y) {
                if(OpponentGrid->gridArr[i][j].getFillColor() == Color(10,10,10,200))
                    OpponentGrid->gridArr[i][j].setFillColor(Color::Yellow);
                else if(OpponentGrid->gridArr[i][j].getFillColor() == Color::Yellow)
                    OpponentGrid->gridArr[i][j].setFillColor(Color::Red);
                for(auto item : OpponentHeroes) {
                    if(item->get_position_on_grid() == goal) {
                        item->getHealth() -= this->getPower();
                        SpecialPower(goal,OpponentGrid,OpponentHeroes);
                        if(item->Name == "MrsGhost") {
                            MrsGhost* MGH = dynamic_cast<MrsGhost*>(item);
                            if(MGH->isVisible()) {
                                OpponentGrid->gridArr[i][j].setTexture(&(item->card->CardTexture));
                                if(item->getHealth() < 1)
                                    OpponentGrid->gridArr[i][j].setFillColor(Color::Red);
                                else
                                    OpponentGrid->gridArr[i][j].setFillColor(Color::White);
                            }
                            else {
                                MGH->ChangeVisibility(true);
                            }
                        }
                        else{
                           OpponentGrid->gridArr[i][j].setTexture(&(item->card->CardTexture));
                           if(item->getHealth() < 1)
                                OpponentGrid->gridArr[i][j].setFillColor(Color::Red);
                           else
                               OpponentGrid->gridArr[i][j].setFillColor(Color::White);
                        }

                        if(item->Name == "Leon") {
                            this->getHealth() -= 2;
                        }
                        else if(item->Name == "Professor") {
                            for(int k=0 ; k<ThisGrid->getRow() ; k++) {
                                for(int m=0 ; m<ThisGrid->getCol() ; m++) {
                                    if(k==this->get_position_on_grid().x && m==this->get_position_on_grid().y) {
                                        ThisGrid->gridArr[k][m].setTexture(&(this->card->CardTexture));
                                        if(this->getHealth() < 1)
                                            ThisGrid->gridArr[k][m].setFillColor(Color::Red);
                                        else
                                            ThisGrid->gridArr[k][m].setFillColor(Color::White);
                                    }
                                }
                            }
                        }
                        return;
                    }
                }
                return;
            }
        }
    }
}

short int& AlphaMan::getHealth()
{
    return health;
}

unsigned short int& AlphaMan::getPower()
{
    return power;
}


void AlphaMan::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

void AlphaMan::SpecialPower(Vector2i goal, Grid* OpponentGrid, std::vector<Hero *>& OpponentHeroes)
{
    for(int i=0 ; i<OpponentGrid->getRow() ; i++) {
        for(int j=0 ; j<OpponentGrid->getCol() ; j++) {
            if(i==goal.x && j==goal.y) {
                for(auto item : OpponentHeroes) {
                    if(item->get_position_on_grid().x == i && item->get_position_on_grid().y == j-1)
                        item->getHealth() --;
                    if(item->get_position_on_grid().x == i-1 && item->get_position_on_grid().y == j)
                        item->getHealth() --;
                    if(item->get_position_on_grid().x == i+1 && item->get_position_on_grid().y == j)
                        item->getHealth() --;
                    if(item->get_position_on_grid().x == i && item->get_position_on_grid().y == j+1)
                        item->getHealth() --;
                }
                return;
            }
        }
    }
}


sf::Vector2i& AlphaMan::get_position_on_grid()
{
    return position_on_grid;
}
