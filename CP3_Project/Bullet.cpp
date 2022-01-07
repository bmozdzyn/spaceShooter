#include "Bullet.h"
#include <iostream>
Bullet::Bullet(const sf::Texture& texture, sf::Vector2f position)
	:Entity(texture, position, sf::IntRect(66, 195, 1, 3))
{
	sprite.setScale(3,3);
}

void Bullet::setDirection(sf::Vector2f dir)
{
	direction = dir;
}

void Bullet::update(float deltatime)
{
	sprite.move(direction * movementSpeed * deltatime);
}
