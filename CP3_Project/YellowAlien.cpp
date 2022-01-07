#include "YellowAlien.h"

void YellowAlien::initVariables()
{
	hp = 0;
	hpMax = 20;
	damage = 3;
	points = 15;
}

YellowAlien::YellowAlien(const sf::Texture& text, sf::Vector2f position)
	: Entity(text, position, sf::IntRect{1,52,16,16})
{
	initVariables();
	sprite.setScale(3,3);
}

bool YellowAlien::canAttack()
{
	if (attackCooldown >= attackCooldownMax)
	{
		attackCooldown = 0.f;
		return true;
	}

	return false;
}

void YellowAlien::updateAttack()
{
	if (attackCooldown < attackCooldownMax)
		attackCooldown += 0.5f;
}

void YellowAlien::update(float deltatime)
{
	timeAlive += deltatime;
	sprite.move(100 * sin(timeAlive * timeAlive) * deltatime, 0);

	updateAttack();
}
