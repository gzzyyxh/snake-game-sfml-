#include <SFML/Graphics.hpp>

#include "Fruit.h"
#include "Game.h"

using namespace sfSnake;

const float Fruit::Radius = 5.f;

int Fruit::grow = 0;

Fruit::Fruit(sf::Vector2f position, int color)
{
	shape_.setPosition(position);
	shape_.setRadius(Fruit::Radius);

	if(color >= 0 && color < 250){
		color %= 2;
		if (color == 0)
			{
				shape_.setFillColor(sf::Color (128, 64, 0));
				if (Game::Bgcolor == 2){
					shape_.setOutlineColor(sf::Color (127, 191, 255));
					shape_.setOutlineThickness(-1.f);
				}
				Fruit::grow = 0;
			}
		else if(color == 1)
			{
				shape_.setFillColor(sf::Color::Black);
				if (Game::Bgcolor == 3){
					shape_.setOutlineColor(sf::Color::White);
					shape_.setOutlineThickness(-1.f);
				}
				Fruit::grow = 0;
			}
	}
	else if(color >= 250 && color < 1000){
		color %= 3;
		switch(color){
			case 0: shape_.setFillColor(sf::Color::Red); Fruit::grow = 3; break;
			case 1: shape_.setFillColor(sf::Color::Green); Fruit::grow = 1; break;
			case 2: shape_.setFillColor(sf::Color::Blue); Fruit::grow = 2; break;
		}
	}
}

void Fruit::render(sf::RenderWindow& window)
{
	window.draw(shape_);
}

sf::FloatRect Fruit::getBounds() const
{
	return shape_.getGlobalBounds();
}