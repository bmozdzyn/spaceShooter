#pragma once
#include "Entity.h"

class BlueAlien :
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
	BlueAlien(const sf::Texture& text, sf::Vector2f position);

	bool canAttack();

	void updateAttack();


	void update(float deltatime) override;

};

