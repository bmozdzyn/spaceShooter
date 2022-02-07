#include "Bullet.h"
#include <iostream>
Bullet::Bullet(const sf::Texture& texture, sf::Vector2f position, int damage)
	:Entity(texture, position, sf::IntRect(66, 195, 1, 3)), damage(damage)
{
	sprite.setScale(3, 3);
	
}

void Bullet::setDirection(sf::Vector2f dir)
{
	direction = dir;
}

void Bullet::update(float deltatime)
{
	sprite.move(direction * movementSpeed * deltatime);
}

int Bullet::getDamage()
{
	return damage;
}
