#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <memory>

#include "Screen.h"

namespace sfSnake
{
class Game
{
public:
	Game();

	void run();

	void handleInput();
	void update(sf::Time delta);
	void render();

	static const int Width = 1200;
	static const int Height = 800;

	static std::shared_ptr<Screen> Screen;

	static int Bgcolor;
	static bool BgMusic;
	static bool music_change;
	static bool selectSound;
private:
	sf::RenderWindow window_;
	sf::Music bgMusic_;

	static const sf::Time TimePerFrame;
};
}


#endif