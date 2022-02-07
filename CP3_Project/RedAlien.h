#pragma once
#include "Entity.h"
class RedAlien :
	public Entity
{
	int points;

	void initVariables();

	sf::Time time;
	float timeAlive{ 0.f };
	int counter;

	void updateAttack();
public:
	RedAlien(const sf::Texture& text, sf::Vector2f position);


	void update(float deltatime);
	
};

