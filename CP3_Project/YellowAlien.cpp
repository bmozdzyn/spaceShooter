#include "YellowAlien.h"

void YellowAlien::initVariables()
{
	hpMax = 30;
	hp = hpMax;
	damage = 30;
	points = 15;

	attackCooldown = 0.f;
	attackCooldownMax = 2.f;
}

YellowAlien::YellowAlien(const sf::Texture& text, sf::Vector2f position)
	: Entity(text, position, sf::IntRect{ 1,52,16,16 })
{
	initVariables();
	sprite.setScale(3, 3);

	timeAlive = (3.0 / 2.0) * 3.141592653589793238;

}


void YellowAlien::updateAttack()
{
	if (attackCooldown < attackCooldownMax)
		attackCooldown += 0.5f;
}

void YellowAlien::update(float deltatime)
{
	//reseting timeAlive every 2s
	timeAlive += deltatime;

	sprite.move(25 * sin(timeAlive) * deltatime, 0);

	static const double pi = 3.141592653589793238;
	if (timeAlive > 2.0* pi)
		timeAlive -= 2.0* pi;


	updateAttack();
}
