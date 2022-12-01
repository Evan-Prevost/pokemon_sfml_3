#pragma once

#include "Entity.h"
#include "GameWindow.h"

class AnimatedMainCharacter : public Entity
{
protected:
    size_t _count;
    int currentAnimation = 0;
    std::vector< std::vector<sf::IntRect>> _animation_pos;
    /*bool moving = false;*/

    // speed main character
    float m_unitDeplacement = 1.0f;

    sf::RectangleShape boxCollision;

public:
    AnimatedMainCharacter(const sf::Texture&, std::vector< std::vector<sf::IntRect>>);
    void nextAnimation(void);
    void handKeys(sf::View &_view);

    //start position box collider
    void setPositionBoxCollider(float x, float y);

    const sf::RectangleShape& getBoxCollision() const;
};