#ifndef GRID_H
#define GRID_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "general.h"
#include "mrsghostcard.h"


class Grid
{
public:
     Grid( unsigned int, unsigned int,sf::RenderWindow*);
    ~Grid();
    void draw();
    unsigned int getRow();
    unsigned int getCol();
    sf::RectangleShape** gridArr;
    sf::Vector2f getCellSize();
    bool aRectIsSelected = false;
    std::vector<unsigned int> SelectedRows;
    std::vector<unsigned int> SelectedCols;
    void setHeroIcon(sf::Vector2f, Heroes);
private:
    unsigned int row;
    unsigned int col;
    sf::RenderWindow* window;
    sf::Vector2f cellSize;
    sf::Texture MrsGhostTexture;
    sf::Texture RobiTexture;
    sf::Texture LeonTexture;
    sf::Texture DrMarryTexture;
    sf::Texture SnipperTexture;
    sf::Texture KratosTexture;
    sf::Texture GiantTexture;
    sf::Texture AlphaManTexture;
    sf::Texture ProfessorTexture;
    sf::Texture Commandertexture;
};

#endif // GRID_H
