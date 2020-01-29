#include "mrsghost.h"
#include <iostream>

using namespace sf;


MrsGhost::MrsGhost(sf::RenderWindow* window) : mrsghostcard(window)
{
    this->window = window;
    Name = "MrsGhost";
    visibility = false;
    health = 15;
    power = 3;
   // mrsghostcard = new MrsGhostCard(window);
    card = &mrsghostcard;
    //mrsghostcard = dynamic_cast<MrsGhostCard*>(card);
}

MrsGhost::~MrsGhost() {}

void MrsGhost::Attack(Vector2i goal , Grid* OpponentGrid , Grid* ThisGrid, std::vector<Hero*>& OpponentHeroes)
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
                        if(item->Name == "MrsGhost") {
                            MrsGhost* MGH = dynamic_cast<MrsGhost*>(item);
                            if(MGH->isVisible()) {
                                OpponentGrid->gridArr[i][j].setTexture(&(item->card->CardTexture));
                                OpponentGrid->gridArr[i][j].setFillColor(Color::White);
                            }
                            else {
                                MGH->ChangeVisibility(true);
                            }
                        }
                        else{
                           OpponentGrid->gridArr[i][j].setTexture(&(item->card->CardTexture));
                           OpponentGrid->gridArr[i][j].setFillColor(Color::White);
                        }
                        item->getHealth() -= this->getPower();
                        if(item->Name == "Leon") {
                            this->getHealth() -= 2;
                        }
                        else if(item->Name == "Professor") {
                            for(int k=0 ; k<ThisGrid->getRow() ; k++) {
                                for(int m=0 ; m<ThisGrid->getCol() ; m++) {
                                    if(k==this->get_position_on_grid().x && m==this->get_position_on_grid().y) {
                                        this->ChangeVisibility(true);
                                        ThisGrid->gridArr[k][m].setTexture(&(this->card->CardTexture));
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

unsigned short int& MrsGhost::getHealth()
{
    return health;
}

unsigned short int& MrsGhost::getPower()
{
    return power;
}

bool& MrsGhost::isVisible()
{
    return visibility;
}

void MrsGhost::ChangeVisibility(bool visibility)
{
    this->visibility = visibility;
}



void MrsGhost::set_position_on_grid(sf::Vector2i position_on_grid)
{
    this->position_on_grid = position_on_grid;

}

sf::Vector2i& MrsGhost::get_position_on_grid()
{
    return position_on_grid;
}
