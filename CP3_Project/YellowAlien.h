#pragma once
#include "Entity.h"
#include <iostream>
class YellowAlien :
	public Entity
{
	int points;

	void initVariables();

	sf::Time time;
	float timeAlive{ 0.f };
	int counter;

	void updateAttack();
public:
	YellowAlien(const sf::Texture& text, sf::Vector2f position);


	void update(float deltatime);
};

