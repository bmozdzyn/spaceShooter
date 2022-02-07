#pragma once
#include "SFML/Graphics.hpp"


// BASE CLASS FOR EVERYTHING ON SCREEN
class Entity :
	public sf::Drawable
{
private:
	void draw(sf::RenderTarget& target, sf::RenderStates) const override;

protected:
	sf::Sprite sprite;
	int hp;
	int hpMax;
	int damage;

	float movementSpeed;
	float attackCooldown;
	float attackCooldownMax;

public:
	Entity(const sf::Texture& texture, sf::Vector2f position, sf::IntRect textRectangle);

	virtual void update(float deltatime) = 0;

	sf::FloatRect getBounds();

	void setPosition(sf::Vector2f pos);
	sf::Vector2f getPosition();

	void receiveDamage(int damage);
	bool canAttack();
	int dealDamage();

	bool isAlive();



	using ptr = std::unique_ptr<Entity>;
};


