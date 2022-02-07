#include "Entity.h"

void Entity::draw(sf::RenderTarget& target, sf::RenderStates) const
{
	target.draw(sprite);
}

Entity::Entity(const sf::Texture& texture, sf::Vector2f position, sf::IntRect textRectangle)
	: sprite(texture, textRectangle)
{
	sprite.setPosition(position);
}

sf::FloatRect Entity::getBounds()
{
	return sprite.getGlobalBounds();
}

void Entity::setPosition(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}

sf::Vector2f Entity::getPosition()
{
	return sprite.getPosition();
}

void Entity::receiveDamage(int damage)
{
	hp -= damage;
}

bool Entity::canAttack()
{
	if (attackCooldown >= attackCooldownMax)
	{
		attackCooldown = 0.f;
		return true;
	}

	return false;
}

int Entity::dealDamage()
{
	return damage;
}

bool Entity::isAlive()
{
	return hp>0;
}
