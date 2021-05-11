#include <SFML/Graphics.hpp>

#include <memory>
#include <ctime>
#include <string>

#include "MenuScreen.h"
#include "Game.h"

using namespace sfSnake;

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 10.f);

std::shared_ptr<Screen> Game::Screen = std::make_shared<MenuScreen>();

int Game::Bgcolor = 3;
bool Game::BgMusic = false;
bool Game::music_change = true;
bool Game::selectSound = true;

Game::Game()
: window_(sf::VideoMode(Game::Width, Game::Height), "sfSnake")
{
	bgMusic_.openFromFile("Music/bg_music.wav");
	bgMusic_.setLoop(true);

	std::string folderPath = "C:\\Snake\\records";

    std::string command;
    command = "mkdir -p " + folderPath;
    system(command.c_str());
}

void Game::handleInput()
{
	sf::Event event;

	while (window_.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window_.close();
	}

	Game::Screen->handleInput(window_);
}

void Game::update(sf::Time delta)
{
	Game::Screen->update(delta);
}

void Game::render()
{
	if (BgMusic && !music_change)
	{bgMusic_.pause(); BgMusic = false;}

	if(!BgMusic && music_change)
	{bgMusic_.play(); BgMusic = true;}

	switch(Game::Bgcolor){
		case 1: window_.clear(sf::Color::White); break;
		case 2: window_.clear(sf::Color (128, 64, 0)); break;
		case 3: window_.clear(sf::Color::Black); break;
	}
	Game::Screen->render(window_);
	window_.display();
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window_.isOpen())
	{
		sf::Time delta = clock.restart();
		timeSinceLastUpdate += delta;

		sf::Time time = clock.getElapsedTime();

		while (timeSinceLastUpdate > Game::TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			handleInput();
			update(TimePerFrame);
		}

		render();
	}
}