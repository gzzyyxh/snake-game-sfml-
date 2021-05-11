#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <SFML/Graphics.hpp>

#include "Screen.h"
#include "Snake.h"
#include "Fruit.h"
#include "Grids.h"

namespace sfSnake
{
class GameScreen : public Screen
{
public:
	GameScreen();

	void handleInput(sf::RenderWindow& window) override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;

	void generateFruit();

	static bool show_grids;

	static bool Game_begin;
	clock_t time_start1;
	clock_t time_start2;
	int time_use;
private:
	Snake snake_;
	std::vector<Fruit> fruit_;
	Grid grids;
	sf::Font font_;
	sf::Text scores;
	sf::Text timeuse;
	sf::FloatRect textBounds1;
	sf::FloatRect textBounds2;
};
}

#endif