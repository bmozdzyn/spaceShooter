#pragma once
#include "Entity.h"
class RedAlien :
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

	sf::Time time;
	float timeAlive{ 0.f };
	int counter;

public:
	RedAlien(const sf::Texture& text, sf::Vector2f position);

	bool canAttack();

	void updateAttack();

	void update(float deltatime) override;
};

