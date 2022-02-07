#include "RedAlien.h"
#include <iostream>

void RedAlien::initVariables()
{
	hpMax = 20;
	hp = hpMax;
	damage = 20;
	points = 10;

	attackCooldown = 0.f;
	attackCooldownMax = 1.f;
}

RedAlien::RedAlien(const sf::Texture& text, sf::Vector2f position)
	: Entity(text, position, sf::IntRect{ 1,1,16,16 })
{
	initVariables();
	sprite.setScale(3, 3);
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

	sprite.move(100 * sin(timeAlive) * deltatime, 0);

	static const double pi = 3.141592653589793238;
	if (timeAlive > 2.0 * pi)
		timeAlive -= 2.0*pi;


	updateAttack();
}
