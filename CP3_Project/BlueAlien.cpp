#include "BlueAlien.h"

void BlueAlien::initVariables()
{
	hp = 0;
	hpMax = 10;
	damage = 1;
	points = 5;
}

BlueAlien::BlueAlien(const sf::Texture& text, sf::Vector2f position)
	: Entity(text, position, sf::IntRect{ 2, 37, 14, 14 })
{
	initVariables();
	sprite.setScale(3, 3);
}

bool BlueAlien::canAttack()
{
	if (attackCooldown >= attackCooldownMax)
	{
		attackCooldown = 0.f;
		return true;
	}

	return false;
}

void BlueAlien::updateAttack()
{
	if (attackCooldown < attackCooldownMax)
		attackCooldown += 0.5f;
}

void BlueAlien::update(float deltatime)
{
	timeAlive += deltatime;
	sprite.move(100 * sin(timeAlive * timeAlive) * deltatime, 0);

	updateAttack();
}
