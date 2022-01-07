#include "Player.h"

void Player::initVariables()
{
	movementSpeed = 8;
	attackCooldownMax = 4.f;
	attackCooldown = attackCooldownMax; //first attack will be instant
}

Player::Player(const sf::Texture& text, sf::Vector2f windowSize)
	: Entity(text, sf::Vector2f(0,0), sf::IntRect(0,0,360,450))
{
	initVariables();
	sprite.setScale(0.12, 0.12);

	sf::Vector2f bounds(getBounds().width, getBounds().height);
	sf::Vector2f middlePos((windowSize - bounds) / 2.f);
	middlePos.y = windowSize.y - 100;
	setPosition(middlePos);
}

void Player::move(const float dirX, const float dirY)
{
	sprite.move(movementSpeed * dirX, movementSpeed * dirY);
}


bool Player::canAttack()
{
	if (attackCooldown >= attackCooldownMax)
	{
		attackCooldown = 0.f;
		return true;
	}

	return false;
}

void Player::updateAttack()
{
	if(attackCooldown < attackCooldownMax)
		attackCooldown += 0.5f;
}

void Player::update(float deltatime)
{
	updateAttack();
}

