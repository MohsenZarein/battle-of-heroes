#include "grid.h"

using namespace sf;

Grid::Grid( unsigned int row, unsigned int col,RenderWindow *window)
{
    this->window = window;
    this->row = row;
    this->col = col;
    cellSize.x = 80.0;
    cellSize.y = 80.0;
    MrsGhostTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/mrs_ghost icon.png");
    RobiTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/robi icon.png");
    LeonTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/leon icon.png");
    DrMarryTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/dr_marry icon.png");
    SnipperTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/sniper icon.png");
    KratosTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/kratos icon.png");
    GiantTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/giant.png");
    AlphaManTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/alpha_man icon.png");
    ProfessorTexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/professoricon.png");
    Commandertexture.loadFromFile("/home/mohsen/QT projecet/BattleOfBasu/images/commander icon.png");

    gridArr = new RectangleShape*[row];
    for(int counter=0;counter<row;counter++){
        gridArr[counter] = new RectangleShape[col];
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
                gridArr[i][j].setSize(cellSize);
                gridArr[i][j].setOutlineColor(Color::Black);
                gridArr[i][j].setFillColor(Color::Transparent);
                gridArr[i][j].setFillColor(Color(10,10,10, 200));
                gridArr[i][j].setOutlineThickness(2.0f);
                gridArr[i][j].setPosition(i*cellSize.x + 5.0f, j*cellSize.y + 5.0f);
        }
    }
}

void Grid::draw()
{

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
                //gridArr[i][j].setSize(cellSize);
                //gridArr[i][j].setOutlineColor(Color::Black);
                //gridArr[i][j].setFillColor(Color::Yellow);
                //gridArr[i][j].setOutlineThickness(1.5f);
                //gridArr[i][j].setPosition(i*cellSize.x + 5.0f, j*cellSize.y + 5.0f);
                this->window->draw(gridArr[i][j]);
        }
    }
}


unsigned int Grid::getRow()
{
    return row;
}

unsigned int Grid::getCol()
{
    return col;
}


Vector2f Grid::getCellSize()
{
    return cellSize;
}

void Grid::setHeroIcon(Vector2f pos, Heroes &HeroName)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (gridArr[i][j].getGlobalBounds().contains(pos))
            {
                switch (HeroName) {
                case MrsGhost_Selected:

                   //MrsGhostCard* MrsGhostIcon = new MrsGhostCard(window);
                    //Icon.getCardTextureSprite().setPosition(pos);
                    //MrsGhostIcon->draw(Vector2f(0.2,0.2),pos);
                    //window->draw( MrsGhostIcon->getCardTextureSprite());
                    gridArr[i][j].setTexture(&MrsGhostTexture);
                    gridArr[i][j].setFillColor(Color::White);
                    break;
                case Robi_Selected:
                    gridArr[i][j].setTexture(&RobiTexture);
                    gridArr[i][j].setFillColor(Color::White);
                    break;
                case Leon_Selected:
                    gridArr[i][j].setTexture(&LeonTexture);
                    gridArr[i][j].setFillColor(Color::White);
                    break;
                 case DrMarry_Selected:
                    gridArr[i][j].setTexture(&DrMarryTexture);
                    gridArr[i][j].setFillColor(Color::White);
                    break;
                 case Snipper_Selected:
                    gridArr[i][j].setTexture(&SnipperTexture);
                    gridArr[i][j].setFillColor(Color::White);
                    break;
                 case Kratos_Selected:
                    gridArr[i][j].setTexture(&KratosTexture);
                    gridArr[i][j].setFillColor(Color::White);
                    break;
                 case Giant_Selected:
                    gridArr[i][j].setTexture(&GiantTexture);
                    gridArr[i][j].setFillColor(Color::White);
                    break;
                 case AlphaMan_Selected:
                    gridArr[i][j].setTexture(&AlphaManTexture);
                    gridArr[i][j].setFillColor(Color::White);
                    break;
                  case Professor_Selected:
                    gridArr[i][j].setTexture(&ProfessorTexture);
                    gridArr[i][j].setFillColor(Color::White);
                    break;
                  case Commander_Selected:
                    gridArr[i][j].setTexture(&Commandertexture);
                    gridArr[i][j].setFillColor(Color::White);
                    break;
                default:
                    break;
                }
            }
        }
    }
}


Grid::~Grid()
{
    for(int i=0;i<row;i++) {
        delete[] gridArr[i];
    }
    delete[] gridArr;
}


