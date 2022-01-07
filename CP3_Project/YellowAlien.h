#pragma once
#include "Entity.h"
#include <iostream>
class YellowAlien :
    public Entity
{
	int hp;
	int hpMax;
	int damage;
	int points;

	//for shooting
	float movementSpeed;
	float attackCooldown;
	float attackCooldownMax;

	void initVariables();

	float timeAlive{ 0.f };

public:
	YellowAlien(const sf::Texture& text, sf::Vector2f position);

	bool canAttack();

	void updateAttack();

	void update(float deltatime) override;
};

