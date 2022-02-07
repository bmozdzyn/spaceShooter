#include "BlueAlien.h"

void BlueAlien::initVariables()
{
	hpMax = 10;
	hp = hpMax;
	damage = 10;
	points = 5;

	attackCooldown = 0.f;
	attackCooldownMax = 1.5f;
}

BlueAlien::BlueAlien(const sf::Texture& text, sf::Vector2f position)
	: Entity(text, position, sf::IntRect{ 2, 37, 14, 14 })
{
	initVariables();
	sprite.setScale(3, 3);
}

void BlueAlien::updateAttack()
{
	if (attackCooldown < attackCooldownMax)
		attackCooldown += 0.5f;
}

void BlueAlien::update(float deltatime)
{
	//reseting timeAlive every 2s
	timeAlive += deltatime;

	sprite.move(100 * sin(2*timeAlive) * deltatime, 0);

	static const double pi = 3.141592653589793238;
	if (timeAlive > 2.0 * pi)
		timeAlive -= 2.0 * pi;



	updateAttack();
}
