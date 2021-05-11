#ifndef HELP_SCREEN_H
#define HELP_SCREEN_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <Screen.h>

namespace sfSnake
{
class HelpScreen : public Screen
{
public:
    HelpScreen();

    void handleInput(sf::RenderWindow& window) override;
    void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;

    void soundPlay(bool);
private:
    sf::Font font_1;
    sf::Font font_2;
    sf::Text text1;
    sf::Text text2;
    sf::Text text3;

    sf::FloatRect textBounds1;
    sf::FloatRect textBounds2;
    sf::FloatRect textBounds3;

    void text_set0(sf::Text& text);
    void text_set1_soundplay(sf::Text& text);
    void text_set2(sf::Text& text);

    sf::Vector2i mouse;

    sf::SoundBuffer selectBuffer_;
	sf::Sound selectSound_;
};
}

#endif
