#include <SFML/Graphics.hpp>

#include <random>
#include <memory>

#include "GameScreen.h"
#include "GameOverScreen.h"
#include "Game.h"

using namespace sfSnake;

bool GameScreen::show_grids = false;
bool GameScreen::Game_begin = false;

GameScreen::GameScreen() : snake_()
{
	font_.loadFromFile("Fonts/game_over.ttf");
	scores.setFont(font_);
	scores.setString("Scores:" + std::to_string(5));
	scores.setCharacterSize(30);
	textBounds1 = scores.getLocalBounds();
	scores.setOrigin(textBounds1.left + textBounds1.width / 2, textBounds1.top + textBounds1.height / 2);
	scores.setPosition(30 + textBounds1.width / 2, 30 + textBounds1.height / 2);
	switch (Game::Bgcolor)
        {
            case 1: scores.setFillColor(sf::Color::Black); break;
            case 2: scores.setFillColor(sf::Color (127, 191, 255)); break;
            case 3: scores.setFillColor(sf::Color::White); break;
        }

	timeuse.setFont(font_);
	timeuse.setString("Time:" + std::to_string(0) + "s");
	timeuse.setCharacterSize(30);
	textBounds2 = timeuse.getLocalBounds();
	timeuse.setOrigin(textBounds2.left + textBounds2.width / 2, textBounds2.top + textBounds2.height / 2);
	timeuse.setPosition(300 + textBounds2.width / 2, 30 + textBounds2.height / 2);
	switch (Game::Bgcolor)
        {
            case 1: timeuse.setFillColor(sf::Color::Black); break;
            case 2: timeuse.setFillColor(sf::Color (127, 191, 255)); break;
            case 3: timeuse.setFillColor(sf::Color::White); break;
        }
}

void GameScreen::handleInput(sf::RenderWindow& window)
{
	snake_.handleInput(window);
}

void GameScreen::update(sf::Time delta)
{
	if (fruit_.size() <= 10)
		generateFruit();

	snake_.update(delta);
	snake_.checkFruitCollisions(fruit_);
	scores.setString("Scores:" + std::to_string(snake_.getSize()));

	if (snake_.hitEdge())
		Game::Screen = std::make_shared<GameOverScreen>(snake_.getSize(), time_use);
}

void GameScreen::render(sf::RenderWindow& window)
{
	if (GameScreen::show_grids == true)
	grids.render(window);

	window.draw(scores);

	if (GameScreen::Game_begin)
	{
		time_start1 = std::clock();
		GameScreen::Game_begin = false;
	}
	time_start2 = std::clock();
	time_use = int(time_start2/(double)CLOCKS_PER_SEC - time_start1/(double)CLOCKS_PER_SEC);
	timeuse.setString("Time:" + std::to_string(time_use) + " s");
	window.draw(timeuse);

	snake_.render(window);
	for (auto fruit : fruit_)
		fruit.render(window);
}

void GameScreen::generateFruit()
{
	static std::default_random_engine engine_pos(time(NULL));
	static std::default_random_engine engine_col(time(NULL));

	static std::uniform_int_distribution<int> cDistribution(0, 1000);

	static std::uniform_int_distribution<int> xDistribution(0, Game::Width - SnakeNode::Width);
	static std::uniform_int_distribution<int> yDistribution(0, Game::Height - SnakeNode::Height - textBounds1.height - 30);

	fruit_.push_back(Fruit(sf::Vector2f(xDistribution(engine_pos), textBounds1.height + 30 + yDistribution(engine_pos)), cDistribution(engine_col)));
}

