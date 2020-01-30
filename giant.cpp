#include "giant.h"
#include "mrsghost.h"
#include <ctime>
#include <iostream>

using namespace sf;

Giant::Giant(sf::RenderWindow* window) : giantcard(window)
{
    Name = "Giant";
    this->window = window;
    health = 20;
    power = 4;
    DonateCondition = false;
    card = &giantcard;
}

Giant::~Giant()
{

}

void Giant::Attack(Vector2i goal , Grid* OpponentGrid , Grid* ThisGrid, std::vector<Hero*> &OpponentHeroes)
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

short int& Giant::getHealth()
{
    return health;
}

unsigned short int& Giant::getPower()
{
    return power;
}


void Giant::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;
}

bool& Giant::isDonateActive()
{
    return DonateCondition;
}

void Giant::setDonateCondition(bool DonateCondition)
{
    this->DonateCondition = DonateCondition;
}

void Giant::Donate(std::vector<Hero*>& Heroes)
{
    srand(time(NULL));
    while(true) {
        unsigned short int RandNum = (rand() % 5) +1;
        int counter = 1;
        for(auto const &item : Heroes) {
            if(RandNum == counter && item->Name != "Giant") {
                item->getHealth() += 3;
                std::cout<<item->Name<<" " <<item->getHealth()<<std::endl;
                return;
            }
            counter++;
        }
    }
}

sf::Vector2i& Giant::get_position_on_grid()
{
    return position_on_grid;
}
