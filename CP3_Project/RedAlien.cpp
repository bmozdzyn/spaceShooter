#include "RedAlien.h"
#include <iostream>

void RedAlien::initVariables()
{
	hp = 0;
	hpMax = 10;
	damage = 1;
	points = 10;
}

RedAlien::RedAlien(const sf::Texture& text, sf::Vector2f position)
	: Entity(text, position, sf::IntRect{1,1,16,16})
{
	initVariables();
	sprite.setScale(3, 3);
}

bool RedAlien::canAttack()
{
	if (attackCooldown >= attackCooldownMax)
	{
		attackCooldown = 0.f;
		return true;
	}

	return false;
}

void RedAlien::updateAttack()
{
	if (attackCooldown < attackCooldownMax)
		attackCooldown += 0.5f;
}

void RedAlien::update(float deltatime)
{
	//reseting timeAlive every 2s
	timeAlive += deltatime;

	sprite.move(100 * sin(timeAlive * timeAlive * timeAlive) * deltatime, 0);

	std::cout << timeAlive;

	if (timeAlive <= -2)
	{
		counter++;
		if (counter % 1 == 0)
		{
			timeAlive = 1.1;
		}
		else if (counter % 2 == 0)
		{
			timeAlive = -1;
		}
	}


	updateAttack();
}
