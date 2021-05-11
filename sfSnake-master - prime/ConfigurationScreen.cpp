#include <SFML/Graphics.hpp>

#include <memory>

#include "Game.h"
#include "GameScreen.h"
#include "MenuScreen.h"
#include "Grids.h"
#include "ConfigurationScreen.h"

using namespace sfSnake;

// bool ConfigurationScreen::mouse_outside = true;

ConfigurationScreen::ConfigurationScreen()
{
    font_.loadFromFile("Fonts/game_over.ttf");
	text_1.setFont(font_);
	text_1.setString("Background color");
	text_1.setCharacterSize(30);

	text_1_1.setFont(font_);
	text_1_1.setString("White");
	text_1_1.setCharacterSize(30);

	text_1_2.setFont(font_);
	text_1_2.setString("Brown");
	text_1_2.setCharacterSize(30);

    text_1_3.setFont(font_);
	text_1_3.setString("Black");
	text_1_3.setCharacterSize(30);

    text_2.setFont(font_);
	text_2.setString("Sound effects");
	text_2.setCharacterSize(30);

    text_2_1.setFont(font_);
	text_2_1.setString("On");
	text_2_1.setCharacterSize(30);

	text_2_2.setFont(font_);
	text_2_2.setString("Off");
	text_2_2.setCharacterSize(30);

	text_3.setFont(font_);
	text_3.setString("Background music");
	text_3.setCharacterSize(30);

	text_3_1.setFont(font_);
	text_3_1.setString("On");
	text_3_1.setCharacterSize(30);

	text_3_2.setFont(font_);
	text_3_2.setString("Off");
	text_3_2.setCharacterSize(30);

	text_4.setFont(font_);
	text_4.setString("show grid?");
	text_4.setCharacterSize(30);

    text_4_1.setFont(font_);
	text_4_1.setString("Yes");
	text_4_1.setCharacterSize(30);

    text_4_2.setFont(font_);
	text_4_2.setString("No");
	text_4_2.setCharacterSize(30);

	text_5.setFont(font_);
	text_5.setString("grid's color");
	text_5.setCharacterSize(30);

	text_5_1.setFont(font_);
	text_5_1.setString("White");
	text_5_1.setCharacterSize(30);

	text_5_2.setFont(font_);
	text_5_2.setString("Brown");
	text_5_2.setCharacterSize(30);

	text_5_3.setFont(font_);
	text_5_3.setString("Black");
	text_5_3.setCharacterSize(30);

    text_6.setFont(font_);
	text_6.setString("Back");
	text_6.setCharacterSize(30);

    text_7.setFont(font_);
	text_7.setString("Start");
	text_7.setCharacterSize(30);

    textBounds1 = text_1.getLocalBounds();
	text_1.setOrigin(textBounds1.left + textBounds1.width / 2,
		textBounds1.top + textBounds1.height / 2);
	text_1.setPosition(270 , 120);

    textBounds1_1 = text_1_1.getLocalBounds();
	text_1_1.setOrigin(textBounds1_1.left + textBounds1_1.width / 2,
		textBounds1_1.top + textBounds1_1.height / 2);
	text_1_1.setPosition(text_1.getPosition().x + textBounds1.width / 2 + (Game::Width - 2 * text_1.getPosition().x - textBounds1_3.width / 2) / 3 , text_1.getPosition().y );

    textBounds1_2 = text_1_2.getLocalBounds();
	text_1_2.setOrigin(textBounds1_2.left + textBounds1_2.width / 2,
		textBounds1_2.top + textBounds1_2.height / 2);
	text_1_2.setPosition(text_1.getPosition().x + textBounds1.width / 2 + (Game::Width - 2 * text_1.getPosition().x - textBounds1_3.width / 2) * 2 / 3 - 30, text_1.getPosition().y );

    textBounds1_3 = text_1_3.getLocalBounds();
	text_1_3.setOrigin(textBounds1_3.left + textBounds1_3.width / 2,
		textBounds1_3.top + textBounds1_3.height / 2);
	text_1_3.setPosition(Game::Width + textBounds1.width / 2 - text_1.getPosition().x - textBounds1_3.width / 2, text_1.getPosition().y );

    textBounds2 = text_2.getLocalBounds();
	text_2.setOrigin(textBounds2.left + textBounds2.width / 2,
		textBounds2.top + textBounds2.height / 2);
	text_2.setPosition(text_1.getPosition().x - textBounds1.width / 2 + textBounds2.width / 2, text_1.getPosition().y + (Game::Height - 2 * text_1.getPosition().y) / 5);

    textBounds2_1 = text_2_1.getLocalBounds();
	text_2_1.setOrigin(textBounds2_1.left + textBounds2_1.width / 2,
		textBounds2_1.top + textBounds1.height / 2);
	text_2_1.setPosition(text_1_1.getPosition().x - textBounds1_1.width / 2 + textBounds2_1.width / 2, text_2.getPosition().y);

    textBounds2_2 = text_2_2.getLocalBounds();
	text_2_2.setOrigin(textBounds2_2.left + textBounds2_2.width / 2,
		textBounds2_2.top + textBounds1.height / 2);
	text_2_2.setPosition(text_1_2.getPosition().x - textBounds1_2.width / 2 + textBounds2_2.width / 2, text_2.getPosition().y);

    textBounds3 = text_3.getLocalBounds();
	text_3.setOrigin(textBounds3.left + textBounds3.width / 2,
		textBounds3.top + textBounds3.height / 2);
	text_3.setPosition(text_1.getPosition().x - textBounds1.width / 2 + textBounds3.width / 2, text_1.getPosition().y + (Game::Height - 2 * text_1.getPosition().y) * 2 / 5);

    textBounds3_1 = text_3_1.getLocalBounds();
	text_3_1.setOrigin(textBounds3_1.left + textBounds3_1.width / 2,
		textBounds3_1.top + textBounds3_1.height / 2);
	text_3_1.setPosition(text_2_1.getPosition().x , text_3.getPosition().y);

    textBounds3_2 = text_3_2.getLocalBounds();
	text_3_2.setOrigin(textBounds3_2.left + textBounds3_2.width / 2,
		textBounds3_2.top + textBounds3_2.height / 2);
	text_3_2.setPosition(text_2_2.getPosition().x, text_3.getPosition().y);

	textBounds4 = text_4.getLocalBounds();
	text_4.setOrigin(textBounds4.left + textBounds4.width / 2,
		textBounds4.top + textBounds4.height / 2);
	text_4.setPosition(text_1.getPosition().x - textBounds1.width / 2 + textBounds4.width / 2, text_1.getPosition().y + (Game::Height - 2 * text_1.getPosition().y) * 3 / 5);

    textBounds4_1 = text_4_1.getLocalBounds();
	text_4_1.setOrigin(textBounds4_1.left + textBounds4_1.width / 2,
		textBounds4_1.top + textBounds4_1.height / 2);
	text_4_1.setPosition(text_1_1.getPosition().x - textBounds1_1.width / 2 + textBounds4_1.width / 2, text_4.getPosition().y);

    textBounds4_2 = text_4_2.getLocalBounds();
	text_4_2.setOrigin(textBounds4_2.left + textBounds4_2.width / 2,
		textBounds4_2.top + textBounds4_2.height / 2);
	text_4_2.setPosition(text_1_2.getPosition().x - textBounds1_2.width / 2 + textBounds4_2.width / 2, text_4.getPosition().y);

	textBounds5 = text_5.getLocalBounds();
	text_5.setOrigin(textBounds5.left + textBounds5.width / 2,
		textBounds3.top + textBounds5.height / 2);
	text_5.setPosition(text_1.getPosition().x - textBounds1.width / 2 + textBounds5.width / 2, text_1.getPosition().y + (Game::Height - 2 * text_1.getPosition().y) * 4 / 5);

    textBounds5_1 = text_5_1.getLocalBounds();
	text_5_1.setOrigin(textBounds5_1.left + textBounds5_1.width / 2,
		textBounds3_1.top + textBounds5_1.height / 2);
	text_5_1.setPosition(text_1_1.getPosition().x, text_5.getPosition().y);

    textBounds5_2 = text_5_2.getLocalBounds();
	text_5_2.setOrigin(textBounds5_2.left + textBounds5_2.width / 2,
		textBounds5_2.top + textBounds5_2.height / 2);
	text_5_2.setPosition(text_1_2.getPosition().x, text_5.getPosition().y);

	textBounds5_3 = text_5_3.getLocalBounds();
	text_5_3.setOrigin(textBounds5_3.left + textBounds5_3.width / 2,
		textBounds5_3.top + textBounds5_3.height / 2);
	text_5_3.setPosition(text_1_3.getPosition().x, text_5.getPosition().y);

    textBounds6 = text_6.getLocalBounds();
	text_6.setOrigin(textBounds6.left + textBounds6.width / 2,
		textBounds4.top + textBounds6.height / 2);
	text_6.setPosition(text_1.getPosition().x - textBounds1.width / 2 + textBounds6.width / 2 , Game::Height - text_1.getPosition().y);

    textBounds7 = text_7.getLocalBounds();
	text_7.setOrigin(textBounds7.left + textBounds7.width / 2,
		textBounds7.top + textBounds7.height / 2);
	text_7.setPosition(Game::Width - text_6.getPosition().x , text_6.getPosition().y);

	selectBuffer_.loadFromFile("Sounds/menu.wav");
	selectSound_.setBuffer(selectBuffer_);
	selectSound_.setVolume(50);
}

void ConfigurationScreen::text_set0(sf::Text& text)
{
	switch (Game::Bgcolor)
	{
		case 1: text.setColor(sf::Color::Black); break;
		case 2: text.setColor(sf::Color (127, 191, 255)); break;
		case 3: text.setColor(sf::Color::White); break;
	}
}

void ConfigurationScreen::text_set1_soundplay(sf::Text& text)
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

void ConfigurationScreen::text_set2(sf::Text& text)
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

void ConfigurationScreen::handleInput(sf::RenderWindow& window)
{
	mouse = sf::Mouse::getPosition(window);

	text_set0 (text_1);
	text_set0 (text_2);
	text_set0 (text_3);
	text_set0 (text_4);
	text_set0 (text_5);

	if (mouse.x > 619 && mouse.x < 737 && mouse.y > 100 & mouse.y < 134){
		text_set1_soundplay(text_1_1);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			text_1_1.setOutlineColor(sf::Color::Green);
			text_1_1.setOutlineThickness(-2.f);
			text_set2(text_1_2);
			text_set2(text_1_3);
			Game::Bgcolor = 1;
		}
	}
	else{
		if(text_1_1.getOutlineThickness() == 0 || text_1_1.getOutlineThickness() == -1.f)
		text_set2(text_1_1);
	}

	if (mouse.x > 808 && mouse.x < 933 && mouse.y > 100 & mouse.y < 134){
		text_set1_soundplay(text_1_2);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			text_1_2.setOutlineColor(sf::Color::Green);
			text_1_2.setOutlineThickness(-2.f);
			text_set2(text_1_1);
			text_set2(text_1_3);
			Game::Bgcolor = 2;
		}
	}
	else{
		if(text_1_2.getOutlineThickness() == 0 || text_1_2.getOutlineThickness() == -1.f)
		text_set2(text_1_2);
	}

	if (mouse.x > 1003 && mouse.x < 1129 && mouse.y > 100 & mouse.y < 134){
		text_set1_soundplay(text_1_3);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			text_1_3.setOutlineColor(sf::Color::Green);
			text_1_3.setOutlineThickness(-2.f);
			text_set2(text_1_1);
			text_set2(text_1_2);
			Game::Bgcolor = 3;
		}
	}
	else{
		if(text_1_3.getOutlineThickness() == 0 || text_1_3.getOutlineThickness() == -1.f)
		text_set2(text_1_3);
	}

	if (mouse.x > 619 && mouse.x < 673 && mouse.y > 214 & mouse.y < 253){
		text_set1_soundplay(text_2_1);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			text_2_1.setOutlineColor(sf::Color::Green);
			text_2_1.setOutlineThickness(-2.f);
			text_set2(text_2_2);
			Game::selectSound = true;
		}
	}
	else{
		if(text_2_1.getOutlineThickness() == 0 || text_2_1.getOutlineThickness() == -1.f)
		text_set2(text_2_1);
	}

	if (mouse.x > 808 && mouse.x < 880 && mouse.y > 214 & mouse.y < 253){
		text_set1_soundplay(text_2_2);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			text_2_2.setOutlineColor(sf::Color::Green);
			text_2_2.setOutlineThickness(-2.f);
			text_set2(text_2_1);
			Game::selectSound = false;
		}
	}
	else{
		if(text_2_2.getOutlineThickness() == 0 || text_2_2.getOutlineThickness() == -1.f)
		text_set2(text_2_2);
	}

	if (mouse.x > 619 && mouse.x < 673 && mouse.y > 325 & mouse.y < 360){
		text_set1_soundplay(text_3_1);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			text_3_1.setOutlineColor(sf::Color::Green);
			text_3_1.setOutlineThickness(-2.f);
			text_set2(text_3_2);
			Game::music_change = true;
		}
	}
	else{
		if(text_3_1.getOutlineThickness() == 0 || text_3_1.getOutlineThickness() == -1.f)
		text_set2(text_3_1);
	}

	if (mouse.x > 808 && mouse.x < 880 && mouse.y > 325 & mouse.y < 360){
		text_set1_soundplay(text_3_2);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			text_3_2.setOutlineColor(sf::Color::Green);
			text_3_2.setOutlineThickness(-2.f);
			text_set2(text_3_1);
			Game::music_change = false;
		}
	}
	else{
		if(text_3_2.getOutlineThickness() == 0 || text_3_2.getOutlineThickness() == -1.f)
		text_set2(text_3_2);
	}

	if (mouse.x > 619 && mouse.x < 689 && mouse.y > 433 & mouse.y < 472){
		text_set1_soundplay(text_4_1);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			text_4_1.setOutlineColor(sf::Color::Green);
			text_4_1.setOutlineThickness(-2.f);
			text_set2(text_4_2);
			GameScreen::show_grids = true;
		}
	}
	else{
		if(text_4_1.getOutlineThickness() == 0 || text_4_1.getOutlineThickness() == -1.f)
		text_set2(text_4_1);
	}

	if (mouse.x > 808 && mouse.x < 862 && mouse.y > 433 & mouse.y < 472){
		text_set1_soundplay(text_4_2);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			text_4_2.setOutlineColor(sf::Color::Green);
			text_4_2.setOutlineThickness(-2.f);
			text_set2(text_4_1);
			GameScreen::show_grids = false;
		}
	}
	else{
		if(text_4_2.getOutlineThickness() == 0 || text_4_2.getOutlineThickness() == -1.f)
		text_set2(text_4_2);
	}

	if (text_4_1.getOutlineThickness() == -2.f){
		if (text_1_1.getOutlineThickness() == 0){
			if (mouse.x > 619 && mouse.x < 737 && mouse.y > 545 & mouse.y < 588){
				text_set1_soundplay(text_5_1);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
					text_5_1.setOutlineColor(sf::Color::Green);
					text_5_1.setOutlineThickness(-2.f);
					text_set2(text_5_2);
					text_set2(text_5_3);
					Grid::color = 1;
				}
			}
			else{
				if(text_5_1.getOutlineThickness() == 0 || text_5_1.getOutlineThickness() == -1.f)
				text_set2(text_5_1);
			}
		}

		if(text_1_2.getOutlineThickness() == 0){
			if (mouse.x > 808 && mouse.x < 934 && mouse.y > 545 & mouse.y < 588){
				text_set1_soundplay(text_5_2);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
					text_5_2.setOutlineColor(sf::Color::Green);
					text_5_2.setOutlineThickness(-2.f);
					text_set2(text_5_1);
					text_set2(text_5_3);
					Grid::color = 2;
				}
			}
			else{
				if(text_5_2.getOutlineThickness() == 0 || text_5_2.getOutlineThickness() == -1.f)
				text_set2(text_5_2);
			}
	}

		if(text_1_3.getOutlineThickness() == 0){
			if (mouse.x > 1002 && mouse.x < 1129 && mouse.y > 545 & mouse.y < 588){
				text_set1_soundplay(text_5_3);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
					text_5_3.setOutlineColor(sf::Color::Green);
					text_5_3.setOutlineThickness(-2.f);
					text_set2(text_5_1);
					text_set2(text_5_2);
					Grid::color = 3;
				}
			}
			else{
				if(text_5_3.getOutlineThickness() == 0 || text_5_3.getOutlineThickness() == -1.f)
				text_set2(text_5_3);
			}
		}
	}

	if (mouse.x > 79 && mouse.x < 173 && mouse.y > 661 & mouse.y < 699){
		text_set1_soundplay(text_6);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			Game::Screen = std::make_shared<MenuScreen>();
			text_6.setOutlineColor(sf::Color::Green);
			text_6.setOutlineThickness(-2.f);
		}
	}
	else{
		text_set2(text_6);
	}

	if (mouse.x > 1015 && mouse.x < 1142 && mouse.y > 661 & mouse.y < 699){
		text_set1_soundplay(text_7);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			Game::Screen = std::make_shared<GameScreen>();
			GameScreen::Game_begin = true;
			text_7.setOutlineColor(sf::Color::Green);
			text_7.setOutlineThickness(-2.f);
		}
	}
	else{
		text_set2(text_7);
	}
}

void ConfigurationScreen::update(sf::Time delta)
{

}

void ConfigurationScreen::render(sf::RenderWindow& window)
{
	window.draw(text_1);
    window.draw(text_1_1);
    window.draw(text_1_2);
    window.draw(text_1_3);

	window.draw(text_2);
    window.draw(text_2_1);
    window.draw(text_2_2);

	window.draw(text_3);
	window.draw(text_3_1);
	window.draw(text_3_2);

    window.draw(text_4);
	window.draw(text_4_1);
	window.draw(text_4_2);

	if (text_4_1.getOutlineThickness() == -2.f){
		window.draw(text_5);

		if (text_1_1.getOutlineThickness() != -2.f)
		window.draw(text_5_1);

		if (text_1_2.getOutlineThickness() != -2.f)
		window.draw(text_5_2);

		if (text_1_3.getOutlineThickness() != -2.f)
		window.draw(text_5_3);
	}

	window.draw(text_6);

	window.draw(text_7);
}

void ConfigurationScreen::soundPlay(bool selectSound)
{
	if(Game::selectSound)
		selectSound_.play();
}