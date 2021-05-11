#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>

#include <AssetManager.h>
#include "SnakeNode.h"
#include "Fruit.h"
#include "Game.h"

namespace sfSnake
{
	enum class Direction
	{
		Left, Right, Up, Down, MousePressed
	};

class Snake
{
public:
	Snake();

	void handleInput(sf::RenderWindow& window);
	void update(sf::Time delta);
	void render(sf::RenderWindow& window);

	void checkFruitCollisions(std::vector<Fruit>& fruits);

	bool hitEdge() const;

	unsigned getSize() const;

private:
	void move();
	void setMovement();
	void grow();
	void checkEdgeCollisions();
	void initNodes();

	bool hitEdge_;

	sf::Vector2f position_;
	float angle = 0.f;
	sf::Vector2f mouse_pos;
	sf::Vector2f snake_pos;
	sf::Vector2f mouse_vector1;
	sf::Vector2f mouse_vector2;
	sf::Vector2f move_vector;
	Direction direction_;

	AssetManager manager;
	sf::Sprite head;

	sf::SoundBuffer pickupBuffer_;
	sf::Sound pickupSound_;

	sf::SoundBuffer dieBuffer_;
	sf::Sound dieSound_;

	std::vector<SnakeNode> nodes_;

	static const int InitialSize;
};
}

#endif