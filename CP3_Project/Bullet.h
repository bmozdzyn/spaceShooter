#pragma once
#include "Entity.h"
class Bullet :
    public Entity
{
    sf::Vector2f direction;
    float movementSpeed{ 150.f };


public:
    Bullet(const sf::Texture& texture, sf::Vector2f position);

    void setDirection(sf::Vector2f dir);

    void update(float deltatime) override;
};

