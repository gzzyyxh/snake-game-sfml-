#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Screen.h"

namespace sfSnake
{
class MenuScreen : public Screen
{
public:
	MenuScreen();

	void handleInput(sf::RenderWindow& window) override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;

	void text_set_1(sf::Text& text);
	void text_set_2(sf::Text& text);

	void soundPlay(bool);

	static bool mouse_outside;
private:
	sf::Font font_;
	sf::Text snakeText_;
	sf::Text text_1;
	sf::Text text_2;
	sf::Text text_3;
	sf::Text text_4;
	sf::Text text_5;

	sf::FloatRect textBounds1;
	sf::FloatRect textBounds2;
	sf::FloatRect textBounds3;
	sf::FloatRect textBounds4;
	sf::FloatRect textBounds5;
	sf::FloatRect snakeTextBounds;
	sf::Vector2i mouse;

	sf::SoundBuffer selectBuffer_;
	sf::Sound selectSound_;
};
}

#endif