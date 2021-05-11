#include <SFML/Graphics.hpp>

#include <memory>
#include <cmath>

#include "Snake.h"
#include "Game.h"
#include "Fruit.h"
#include "SnakeNode.h"
#include "GameOverScreen.h"

using namespace sfSnake;

const int Snake::InitialSize = 5;

Snake::Snake() : direction_(Direction::Up), hitEdge_(false)
{
	head = sf::Sprite(AssetManager::GetTexture("1.png"));
	head.setScale(0.25, 0.25);
	head.setOrigin(sf::Vector2f(100.f, 100.f));
	head.setPosition(Game::Width / 2 - SnakeNode::Width / 2, Game::Height / 2 - SnakeNode::Height / 2);

	initNodes();

	pickupBuffer_.loadFromFile("Sounds/pickup.wav");
	pickupSound_.setBuffer(pickupBuffer_);
	pickupSound_.setVolume(30);

	dieBuffer_.loadFromFile("Sounds/die.wav");
	dieSound_.setBuffer(dieBuffer_);
	dieSound_.setVolume(50);
}

void Snake::initNodes()
{
	for (int i = 0; i < Snake::InitialSize; ++i)
	{
		nodes_.push_back(SnakeNode(sf::Vector2f(
			Game::Width / 2 - SnakeNode::Width / 2,
			Game::Height / 2 - (SnakeNode::Height / 2) + (SnakeNode::Height * i))));
	}
}

void Snake::setMovement()
{
	snake_pos = head.getPosition();
	mouse_vector2 = sf::Vector2f(mouse_pos.x - snake_pos.x, mouse_pos.y - snake_pos.y);
	if (mouse_vector2.x >= 0) mouse_vector1 = sf::Vector2f(0,-1.f);
	else mouse_vector1 = sf::Vector2f(0,1.f);
	float value = (mouse_vector1.x * mouse_vector2.x + mouse_vector1.y * mouse_vector2.y) / (sqrt(pow(mouse_vector1.x, 2) + pow(mouse_vector1.y, 2)) * sqrt(pow(mouse_vector2.x, 2) + pow(mouse_vector2.y, 2)));
	if (value > 1.0) value = 1.0;
	angle = acos(value) *180.f / 3.141592653589793;
	if (mouse_vector1.y > 0) angle += 180;

	float norm = sqrt(pow(mouse_vector2.x, 2) + pow(mouse_vector2.y, 2));
	move_vector = sf::Vector2f(mouse_vector2.x / norm * SnakeNode::Height, mouse_vector2.y / norm * SnakeNode::Height);
}

void Snake::handleInput(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		direction_ = Direction::Up;
		mouse_pos = sf::Vector2f(head.getPosition().x, 0);
		setMovement();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		direction_ = Direction::Down;
		mouse_pos = sf::Vector2f(head.getPosition().x, Game::Height);
		setMovement();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		direction_ = Direction::Left;
		mouse_pos = sf::Vector2f(0, head.getPosition().y);
		setMovement();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direction_ = Direction::Right;
		mouse_pos = sf::Vector2f(Game::Width, head.getPosition().y);
		setMovement();
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		direction_ = Direction::MousePressed;
		mouse_pos = sf::Vector2f(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y));
		setMovement();
	}
}

void Snake::update(sf::Time delta)
{
	move();
	checkEdgeCollisions();
}

void Snake::checkFruitCollisions(std::vector<Fruit>& fruits)
{
	decltype(fruits.begin()) toRemove = fruits.end();

	for (auto it = fruits.begin(); it != fruits.end(); ++it)
	{
		if (it->getBounds().intersects(head.getGlobalBounds()))
			toRemove = it;
	}

	if (toRemove != fruits.end())
	{
		if (Game::selectSound)
		pickupSound_.play();
		grow();
		fruits.erase(toRemove);
	}
}

void Snake::grow()
{
	for(int i = 1; i <= Fruit::grow; i++){
		switch (direction_)
		{
		case Direction::Up:
			nodes_.push_back(SnakeNode(sf::Vector2f(nodes_[nodes_.size() - 1].getPosition().x,
				nodes_[nodes_.size() - 1].getPosition().y + SnakeNode::Height)));
			break;
		case Direction::Down:
			nodes_.push_back(SnakeNode(sf::Vector2f(nodes_[nodes_.size() - 1].getPosition().x,
				nodes_[nodes_.size() - 1].getPosition().y - SnakeNode::Height)));
			break;
		case Direction::Left:
			nodes_.push_back(SnakeNode(sf::Vector2f(nodes_[nodes_.size() - 1].getPosition().x + SnakeNode::Width,
				nodes_[nodes_.size() - 1].getPosition().y)));
			break;
		case Direction::Right:
			nodes_.push_back(SnakeNode(sf::Vector2f(nodes_[nodes_.size() - 1].getPosition().x - SnakeNode::Width,
				nodes_[nodes_.size() - 1].getPosition().y)));
			break;
		case Direction::MousePressed:
			sf::Vector2f pos_1 = sf::Vector2f(nodes_[nodes_.size() - 2].getPosition().x, nodes_[nodes_.size() - 2].getPosition().y);
			sf::Vector2f pos_2 = sf::Vector2f(nodes_[nodes_.size() - 1].getPosition().x, nodes_[nodes_.size() - 1].getPosition().y);
			sf::Vector2f add_vector = sf::Vector2f(pos_2.x - pos_2.x, pos_1.y - pos_1.y);
			float norm = sqrt(pow(add_vector.x, 2) + pow(add_vector.y, 2));
			nodes_.push_back(SnakeNode(sf::Vector2f(add_vector.x / norm * SnakeNode::Height, add_vector.y / norm * SnakeNode::Height)));
			break;
		}
	}
}

unsigned Snake::getSize() const
{
	return nodes_.size();
}

bool Snake::hitEdge() const
{
	return hitEdge_;
}

void Snake::checkEdgeCollisions()
{
	sf::Sprite& headNode = head;

	if (headNode.getPosition().x <= 0 || headNode.getPosition().x >= Game::Width || headNode.getPosition().y <= 0 || headNode.getPosition().y >= Game::Height){
		if (Game::selectSound)
		dieSound_.play();
		sf::sleep(sf::seconds(dieBuffer_.getDuration().asSeconds()));
		hitEdge_ = true;
	}
}

void Snake::move()
{
	for (decltype(nodes_.size()) i = nodes_.size() - 1; i > 0; --i)
	{
		nodes_[i].setPosition(nodes_.at(i - 1).getPosition());
		nodes_[i].setRotation(nodes_.at(i - 1).getRotation());
	}
	nodes_[0].setPosition(head.getPosition());
	nodes_[0].setRotation(head.getRotation());

	switch (direction_)
	{
	case Direction::Up:
		head.move(0, -SnakeNode::Height);
		head.setRotation(angle);
		break;
	case Direction::Down:
		head.move(0, SnakeNode::Height);
		head.setRotation(angle);
		break;
	case Direction::Left:
		head.move(-SnakeNode::Width, 0);
		head.setRotation(angle);
		break;
	case Direction::Right:
		head.move(SnakeNode::Width, 0);
		head.setRotation(angle);
		break;
	case Direction::MousePressed:
		head.move(move_vector.x, move_vector.y);
		head.setRotation(angle);
		break;
	}
}

void Snake::render(sf::RenderWindow& window)
{
	window.draw(head);
	for (auto node: nodes_){
		node.render_c(window);
		node.render_r(window);
	}
}