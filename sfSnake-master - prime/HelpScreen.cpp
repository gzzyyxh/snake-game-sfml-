#include <SFML/Graphics.hpp>

#include <memory>

#include "HelpScreen.h"
#include "Game.h"
#include "MenuScreen.h"
#include "GameScreen.h"

using namespace sfSnake;

HelpScreen::HelpScreen()
{
    font_1.loadFromFile("Fonts/statements.ttf");
	text1.setFont(font_1);
	text1.setString("In this game, you can use the up, down, left, and right buttons to control the"
					"\n\nmovement of the snake, or you can click the left mouse button to control the"
					"\n\nmovement of the snake.There are five kinds of fruits: black, brown, blue, green,"
					"\n\nand red. The first two kinds of fruits do not score, and the last three kinds of"
					"\n\nfruits get 1, 2, 3 points in sequence.The game ends when any part of the snake"
					"\n\ntouches the border, and the snake itself can overlap.The local game record will"
					"\n\nbe saved at the end of the game. When the game is played for the first time,"
					"\n\nthe history record cannot be opened.");
	text1.setCharacterSize(30);

	font_2.loadFromFile("Fonts/game_over.ttf");
	text2.setFont(font_2);
	text2.setString("Back");
	text2.setCharacterSize(30);

	text3.setFont(font_2);
	text3.setString("Start");
	text3.setCharacterSize(30);

    textBounds1 = text1.getLocalBounds();
	text1.setOrigin(textBounds1.left + textBounds1.width / 2,
		textBounds1.top + textBounds1.height / 2);
	text1.setPosition(Game::Width / 2, Game::Height / 2 - 48);

	textBounds2 = text2.getLocalBounds();
	text2.setOrigin(textBounds2.left + textBounds2.width / 2,
		textBounds2.top + textBounds2.height / 2);
	text2.setPosition(124.5 , 680);

	textBounds3 = text3.getLocalBounds();
	text3.setOrigin(textBounds3.left + textBounds3.width / 2,
		textBounds3.top + textBounds3.height / 2);
	text3.setPosition(1075.5 , 680);

	selectBuffer_.loadFromFile("Sounds/menu.wav");
	selectSound_.setBuffer(selectBuffer_);
	selectSound_.setVolume(50);
}

void HelpScreen::handleInput(sf::RenderWindow& window)
{
	mouse = sf::Mouse::getPosition(window);

	text_set0 (text1);
	text_set0 (text2);
	text_set0 (text3);

	if (mouse.x > 79 && mouse.x < 173 && mouse.y > 661 & mouse.y < 699){
		text_set1_soundplay(text2);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			Game::Screen = std::make_shared<MenuScreen>();
			text2.setOutlineColor(sf::Color::Green);
			text2.setOutlineThickness(-2.f);
		}
	}
	else{
		text_set2(text2);
	}

	if (mouse.x > 1015 && mouse.x < 1142 && mouse.y > 661 & mouse.y < 699){
		text_set1_soundplay(text3);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			Game::Screen = std::make_shared<GameScreen>();
			GameScreen::Game_begin = true;
			text3.setOutlineColor(sf::Color::Green);
			text3.setOutlineThickness(-2.f);
		}
	}
	else{
		text_set2(text3);
	}
}

void HelpScreen::update(sf::Time delta)
{

}

void HelpScreen::render(sf::RenderWindow& window)
{
	window.draw(text1);
	window.draw(text2);
	window.draw(text3);
}

void HelpScreen::text_set0(sf::Text& text)
{
	switch (Game::Bgcolor)
	{
		case 1: text.setColor(sf::Color::Black); break;
		case 2: text.setColor(sf::Color (127, 191, 255)); break;
		case 3: text.setColor(sf::Color::White); break;
	}
}

void HelpScreen::text_set1_soundplay(sf::Text& text)
{
	if (text.getOutlineThickness() == 0){
		text.setColor(sf::Color::Blue);
		text.setStyle(sf::Text::Bold);
		text.setScale(1.5, 1.5);
		text.setOutlineThickness(-1.f);
		text.setOutlineColor(sf::Color::Blue);
		soundPlay(Game::selectSound);
	}
}

void HelpScreen::text_set2(sf::Text& text)
{
	if (Game::Bgcolor == 1)
	text.setColor(sf::Color::Black);
	else if (Game::Bgcolor == 2)
	text.setColor(sf::Color (127, 191, 255));
	else if (Game::Bgcolor == 3)
	text.setColor(sf::Color::White);
	text.setStyle(sf::Text::Regular);
	text.setScale(1.f, 1.f);
	text.setOutlineThickness(0);
}

void HelpScreen::soundPlay(bool selectSound)
{
	if(Game::selectSound)
		selectSound_.play();
}
