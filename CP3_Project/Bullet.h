#pragma once
#include "Entity.h"
class Bullet :
    public Entity
{
    sf::Vector2f direction;
    float movementSpeed{ 150.f };
    int damage;


public:
    Bullet(const sf::Texture& texture, sf::Vector2f position, int damage);

    void setDirection(sf::Vector2f dir);

    void update(float deltatime) override;

    int getDamage();
};

