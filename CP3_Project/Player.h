#pragma once
#include <iostream>
#include "Entity.h"

class Player :
	public Entity
{
	void initVariables();

public: 

	Player(const sf::Texture& text, sf::Vector2f windowSize);

	void move(const float dirX, const float dirY);

	int currentHP();

	void updateAttack();
	void updateHP(int damage);
	void update(float deltatime);
};

