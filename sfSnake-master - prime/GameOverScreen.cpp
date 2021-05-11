#include <SFML/Graphics.hpp>

#include <memory>
#include <fstream>
#include<time.h>

#include "Game.h"
#include "GameScreen.h"
#include "GameOverScreen.h"

using namespace sfSnake;

GameOverScreen::GameOverScreen(std::size_t score, int time_use) : score_(score), time_use_(time_use)
{
	font_.loadFromFile("Fonts/statements.ttf");
	text_.setFont(font_);
	text_.setString("Your score: " + std::to_string(score_) + "!"
		"\n\nYou used " + std::to_string(time_use_) + " s!"
		"\n\nPress [SPACE] to retry"
		"\n\nPress [ESC] to quit");
	text_.setCharacterSize(50);
	switch (Game::Bgcolor)
	{
		case 1: text_.setColor(sf::Color::Black); break;
		case 2: text_.setColor(sf::Color (127, 191, 255)); break;
		case 3: text_.setColor(sf::Color::White); break;
	}

	sf::FloatRect textBounds = text_.getLocalBounds();
	text_.setOrigin(textBounds.left + textBounds.width / 2,
		textBounds.top + textBounds.height / 2);
	text_.setPosition(Game::Width / 2, Game::Height / 2);

	record();
}

void GameOverScreen::handleInput(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Game::Screen = std::make_shared<GameScreen>();
		GameScreen::Game_begin = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window.close();
}

void GameOverScreen::update(sf::Time delta)
{

}

void GameOverScreen::render(sf::RenderWindow& window)
{
	window.draw(text_);
}

void GameOverScreen::record()
{
	time_t now_time=time(NULL);
	tm*  t_tm = localtime(&now_time);

	std::ofstream file;
	file.open("C:\\Snake\\records\\records.txt", std::ios::out | std::ios::app);

	file << asctime(t_tm) << "Your Score: " + std::to_string(score_) + "; " + "Time Using: " + std::to_string(time_use_) + " s\n" << std::endl;
	file.close();
}