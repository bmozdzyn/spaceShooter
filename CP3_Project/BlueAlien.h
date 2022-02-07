#pragma once
#include "Entity.h"

class BlueAlien :
	public Entity
{

	int points;

	void initVariables();

	sf::Time time;
	float timeAlive{ 0.f };
	int counter;

	void updateAttack();
public:
	BlueAlien(const sf::Texture& text, sf::Vector2f position);


	void update(float deltatime);

};

