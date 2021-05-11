#ifndef GRID_H
#define GRID_H

#include <vector>
#include <SFML/Graphics.hpp>

namespace sfSnake
{
class Grid
{
public:
	Grid(int space = 150);

	void render(sf::RenderWindow& window);

    static int color;
private:
	std::vector<sf::RectangleShape> grids;
};
}

#endif