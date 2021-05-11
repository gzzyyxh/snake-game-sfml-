#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <SFML/Graphics.hpp>

#include <Screen.h>

namespace sfSnake
{
class ConfigurationScreen : public Screen
{
public:
	ConfigurationScreen();

	void handleInput(sf::RenderWindow& window) override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;

	void soundPlay(bool);

	static bool show_grid;
private:
	sf::Font font_;
	sf::Text text_1;
	sf::Text text_1_1;
	sf::Text text_1_2;
    sf::Text text_1_3;

    sf::Text text_2;
    sf::Text text_2_1;
    sf::Text text_2_2;

    sf::Text text_3;
    sf::Text text_3_1;
	sf::Text text_3_2;

	sf::Text text_4;
	sf::Text text_4_1;
	sf::Text text_4_2;

	sf::Text text_5;
	sf::Text text_5_1;
	sf::Text text_5_2;
   	sf::Text text_5_3;

	sf::Text text_6;

	sf::Text text_7;

	sf::FloatRect textBounds1;
	sf::FloatRect textBounds1_1;
    sf::FloatRect textBounds1_2;
    sf::FloatRect textBounds1_3;

	sf::FloatRect textBounds2;
	sf::FloatRect textBounds2_1;
    sf::FloatRect textBounds2_2;

	sf::FloatRect textBounds3;
	sf::FloatRect textBounds3_1;
    sf::FloatRect textBounds3_2;

	sf::FloatRect textBounds4;
	sf::FloatRect textBounds4_1;
	sf::FloatRect textBounds4_2;

	sf::FloatRect textBounds5;
	sf::FloatRect textBounds5_1;
	sf::FloatRect textBounds5_2;
	sf::FloatRect textBounds5_3;

	sf::FloatRect textBounds6;

	sf::FloatRect textBounds7;

	void text_set0(sf::Text& text);
	void text_set1_soundplay(sf::Text& text);
	void text_set2(sf::Text& text);

	sf::Vector2i mouse;

	sf::SoundBuffer selectBuffer_;
	sf::Sound selectSound_;
};
}

#endif