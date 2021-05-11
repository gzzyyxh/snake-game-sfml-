#include <SFML/Graphics.hpp>

#include <memory>

#include "GameScreen.h"
#include "MenuScreen.h"
#include "ConfigurationScreen.h"
#include "Game.h"
#include "HelpScreen.h"

using namespace sfSnake;

bool MenuScreen::mouse_outside = true;

MenuScreen::MenuScreen()
{
	font_.loadFromFile("Fonts/game_over.ttf");
	text_1.setFont(font_);
	text_1.setString("Play");
	text_1.setCharacterSize(50);

	text_2.setFont(font_);
	text_2.setString("Configuration");
	text_2.setCharacterSize(50);

	text_3.setFont(font_);
	text_3.setString("History Record");
	text_3.setCharacterSize(50);

	text_4.setFont(font_);
	text_4.setString("Help");
	text_4.setCharacterSize(50);

	text_5.setFont(font_);
	text_5.setString("Quit");
	text_5.setCharacterSize(50);

	snakeText_.setFont(font_);
	snakeText_.setString("Snake!");
	snakeText_.setColor(sf::Color::Green);
	snakeText_.setCharacterSize(130);
	snakeText_.setStyle(sf::Text::Bold);
	snakeText_.setOutlineColor(sf::Color::Yellow);
	snakeText_.setOutlineThickness(-2.f);

	textBounds1 = text_1.getLocalBounds();
	text_1.setOrigin(textBounds1.left + textBounds1.width / 2,
		textBounds1.top + textBounds1.height / 2);
	text_1.setPosition(Game::Width / 2, Game::Height / 3 + 20);

	textBounds2 = text_2.getLocalBounds();
	text_2.setOrigin(textBounds2.left + textBounds2.width / 2,
		textBounds2.top + textBounds2.height / 2);
	text_2.setPosition(Game::Width / 2, Game::Height / 3 + 130);

	textBounds3 = text_3.getLocalBounds();
	text_3.setOrigin(textBounds3.left + textBounds3.width / 2,
		textBounds3.top + textBounds3.height / 2);
	text_3.setPosition(Game::Width / 2, Game::Height / 3 + 240);

	textBounds4 = text_4.getLocalBounds();
	text_4.setOrigin(textBounds4.left + textBounds4.width / 2,
		textBounds5.top + textBounds4.height / 2);
	text_4.setPosition(Game::Width / 2, Game::Height / 3 + 350);


	textBounds5 = text_5.getLocalBounds();
	text_5.setOrigin(textBounds5.left + textBounds5.width / 2,
		textBounds5.top + textBounds5.height / 2);
	text_5.setPosition(Game::Width / 2, Game::Height / 3 + 460);

	snakeTextBounds = snakeText_.getLocalBounds();
	snakeText_.setOrigin(snakeTextBounds.left + snakeTextBounds.width / 2,
		snakeTextBounds.top + snakeTextBounds.height / 2);
	snakeText_.setPosition(Game::Width / 2, Game::Height / 5);

	selectBuffer_.loadFromFile("Sounds/menu.wav");
	selectSound_.setBuffer(selectBuffer_);
	selectSound_.setVolume(50);
}

void MenuScreen::handleInput(sf::RenderWindow& window)
{
	mouse = sf::Mouse::getPosition(window);

	if (mouse.x > 520 && mouse.x < 678 && mouse.y > 257 & mouse.y < 315){
		text_set_1(text_1);
		soundPlay(Game::selectSound);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			Game::Screen = std::make_shared<GameScreen>();
			GameScreen::Game_begin = true;
		}
	}
	else{
		text_set_2(text_1);
	}

	if(mouse.x > 335 && mouse.x < 859 && mouse.y > 367 & mouse.y < 431){
		text_set_1(text_2);
		soundPlay(Game::selectSound);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			Game::Screen = std::make_shared<ConfigurationScreen>();
	}
	else{
		text_set_2(text_2);
	}

	if(mouse.x > 318 && mouse.x < 880 && mouse.y > 476 & mouse.y < 534){
		text_set_1(text_3);
		soundPlay(Game::selectSound);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			system("C:\\Snake\\records\\records.txt");
	}
	else{
		text_set_2(text_3);
	}

	if(mouse.x > 517 && mouse.x < 677 && mouse.y > 598 & mouse.y < 657){
		text_set_1(text_4);
		soundPlay(Game::selectSound);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			Game::Screen = std::make_shared<HelpScreen>();
	}
	else{
		text_set_2(text_4);
	}

	if(mouse.x > 519 && mouse.x < 676 && mouse.y > 696 & mouse.y < 753){
		text_set_1(text_5);
		soundPlay(Game::selectSound);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			window.close();
	}
	else{
		text_set_2(text_5);
	}
}

void MenuScreen::update(sf::Time delta)
{
	static bool movingLeft = false;
	static bool movingRight = true;

	if (movingRight)
	{
		snakeText_.rotate(delta.asSeconds());

		if (static_cast<int>(snakeText_.getRotation()) == 10)
		{
			movingRight = false;
			movingLeft = true;
		}
	}

	if (movingLeft)
	{
		snakeText_.rotate(-delta.asSeconds());

		if (static_cast<int>(snakeText_.getRotation()) == (360 - 10))
		{
			movingLeft = false;
			movingRight = true;
		}
	}

	if (text_1.getOutlineThickness() == 0 && text_2.getOutlineThickness() == 0 && text_3.getOutlineThickness() == 0 && text_4.getOutlineThickness() == 0 && text_5.getOutlineThickness() == 0)
	mouse_outside = true;
}

void MenuScreen::render(sf::RenderWindow& window)
{
	window.draw(text_1);
	window.draw(text_2);
	window.draw(text_3);
	window.draw(text_4);
	window.draw(text_5);
	window.draw(snakeText_);
}

void MenuScreen::text_set_1(sf::Text& text)
{
	text.setColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold);
	text.setOutlineColor(sf::Color::Yellow);
	text.setOutlineThickness(-1.f);
}

void MenuScreen::text_set_2(sf::Text& text)
{
	switch (Game::Bgcolor)
	{
		case 1: text.setColor(sf::Color::Black); break;
		case 2: text.setColor(sf::Color (127, 191, 255)); break;
		case 3: text.setColor(sf::Color::White); break;
	}
	text.setStyle(sf::Text::Regular);
	text.setOutlineThickness(0);
}

void MenuScreen::soundPlay(bool selectSound)
{
	if(Game::selectSound){
		while (mouse_outside)
		{
			selectSound_.play();
			mouse_outside = false;
		}
	}
}