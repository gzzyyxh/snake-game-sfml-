#include <SFML/Graphics.hpp>
#include <iostream>

#include "SnakeNode.h"

using namespace sfSnake;

const float SnakeNode::Width = 15.f;
const float SnakeNode::Height = 15.f;

SnakeNode_shape::SnakeNode_shape(){
	circle_.setFillColor(sf::Color::Yellow);
	rectangle_.setFillColor(sf::Color::Red);
	circleBounds = circle_.getLocalBounds();
	rectangleBounds = rectangle_.getLocalBounds();
}

void SnakeNode_shape::setPosition(sf::Vector2f position){
	circle_.setOrigin(circleBounds.left + circle_.getRadius(), circleBounds.top + circle_.getRadius());
	circle_.setPosition(position);
	rectangle_.setOrigin(rectangleBounds.left + rectangle_.getSize().x / 2, rectangleBounds.top + rectangle_.getSize().y / 2);
	rectangle_.setPosition(position);
}

void SnakeNode_shape::setSize(sf::Vector2f size){
	circle_.setRadius(size.x / 2.f);
	rectangle_.setSize(sf::Vector2f(size.y, size.x / 3));
}

void SnakeNode_shape::setRotation(float angle){
	rectangle_.setRotation(angle);
}

sf::CircleShape SnakeNode_shape::getcircle_() const{
	return circle_;
}

sf::RectangleShape SnakeNode_shape::getrectangle_() const{
	return rectangle_;
}

SnakeNode::SnakeNode(sf::Vector2f position)
: position_(position)
{
	shape_.setPosition(position_);
	shape_.setSize(sf::Vector2f(SnakeNode::Height, SnakeNode::Width));
}

void SnakeNode::setPosition(sf::Vector2f position)
{
	position_ = position;
	shape_.setPosition(position_);
}

void SnakeNode::setPosition(float x, float y)
{
	position_.x = x;
	position_.y = y;
	shape_.setPosition(position_);
}

void SnakeNode::setRotation(float angle){
	angle_ = angle;
	shape_.setRotation(angle);
}

float SnakeNode::getRotation() const
{
	return angle_;
}

void SnakeNode::move(float xOffset, float yOffset)
{
	position_.x += xOffset;
	position_.y += yOffset;
	shape_.setPosition(position_);
}

sf::FloatRect SnakeNode::getBounds() const
{
	return shape_.getcircle_().getGlobalBounds();
}

sf::Vector2f SnakeNode::getPosition() const
{
	return position_;
}

void SnakeNode::render_c(sf::RenderWindow& window)
{
	window.draw(shape_.getcircle_());
}

void SnakeNode::render_r(sf::RenderWindow& window)
{
	window.draw(shape_.getrectangle_());
}