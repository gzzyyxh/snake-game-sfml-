#ifndef SNAKE_NODE_H
#define SNAKE_NODE_H

#include <SFML/Graphics.hpp>

namespace sfSnake
{

class SnakeNode_shape
{
public:
	SnakeNode_shape();

	void setSize(sf::Vector2f size);
	void setPosition(sf::Vector2f position);
	void setRotation(float angle);
	sf::CircleShape getcircle_() const ;
	sf::RectangleShape getrectangle_() const ;
private:
	sf::CircleShape circle_;
	sf::RectangleShape rectangle_;

	sf::FloatRect circleBounds;
	sf::FloatRect rectangleBounds;
};


class SnakeNode
{
public:
	SnakeNode(sf::Vector2f position = sf::Vector2f(0, 0));

	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);
	void setRotation(float angle);

	void move(float xOffset, float yOffset);

	void render_c(sf::RenderWindow& window);
	void render_r(sf::RenderWindow& window);

	sf::Vector2f getPosition() const;
	sf::FloatRect getBounds() const;
	float getRotation() const;

	static const float Width;
	static const float Height;

private:
	SnakeNode_shape shape_;
	sf::Vector2f position_;
	float angle_;
};
}

#endif