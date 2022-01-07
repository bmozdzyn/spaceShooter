#pragma once
#include <iostream>
#include "Entity.h"

class Player :
	public Entity
{
	float movementSpeed;

	float attackCooldown;
	float attackCooldownMax;

	void initVariables();

public:
	Player(const sf::Texture& text, sf::Vector2f windowSize);

	void move(const float dirX, const float dirY);

	bool canAttack();

	void updateAttack();
	void update(float deltatime) override;
};

