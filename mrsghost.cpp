#include "mrsghost.h"
#include <iostream>

using namespace sf;


MrsGhost::MrsGhost(sf::RenderWindow* window) : mrsghostcard(window)
{
    this->window = window;
    Name = "MrsGhost";
    visibility = false;
   // mrsghostcard = new MrsGhostCard(window);
    card = &mrsghostcard;
    //mrsghostcard = dynamic_cast<MrsGhostCard*>(card);
}

MrsGhost::~MrsGhost() {}

void MrsGhost::Attack(Vector2i goal , Grid* OpponentGrid , std::vector<Hero*>& OpponentHeroes)
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

                    }
                }
            }
        }
    }
}

float& MrsGhost::getHealth()
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
