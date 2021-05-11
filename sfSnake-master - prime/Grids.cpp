#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Grids.h"

using namespace sfSnake;

int Grid::color = 1;

Grid::Grid (int space)
{
    int herizon = (Game::Width % space) / 2;
    int columns = (Game::Width - 2 * herizon) / space;

    int vertical = (Game::Height % space) /2;
    int rows = (Game::Height - 2 * vertical) / space;

    for (int r = 1; r <= rows + 1; r++){
        sf::RectangleShape col(sf::Vector2f(Game::Width, 1.f));
        sf::FloatRect Bounds = col.getLocalBounds();
        col.setOrigin(Bounds.left + Bounds.width / 2 , Bounds.top + Bounds.height / 2);
        col.setPosition(sf::Vector2f(Game::Width / 2, vertical + space * (r - 1)));
        grids.push_back(col);
    }

    for (int c = 1; c <= columns; c++){
        sf::RectangleShape row(sf::Vector2f(1.f, Game::Height));
        sf::FloatRect Bounds = row.getLocalBounds();
        row.setOrigin(Bounds.left + Bounds.width / 2 , Bounds.top + Bounds.height / 2);
        row.setPosition(sf::Vector2f(herizon + space * (c - 1), Game::Height / 2));
        grids.push_back(row);
    }
}

void Grid::render(sf::RenderWindow& window)
{
    for(auto& object: grids){
        switch (Grid::color)
        {
            case 1: object.setFillColor(sf::Color::White); break;
            case 2: object.setFillColor(sf::Color (128, 64, 0)); break;
            case 3: object.setFillColor(sf::Color::Black); break;
        }
        window.draw(object);
    }
}