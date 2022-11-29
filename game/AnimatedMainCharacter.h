#pragma once

#include "Entity.h"

class AnimatedMainCharacter : public Entity
{
protected:
    size_t _count;
    std::vector< std::vector<sf::IntRect>> _animation_pos;
    int currentAnimation = 0;
    // speed main character
    float m_speed = 1.0f;

public:
    AnimatedMainCharacter(const sf::Texture&, std::vector< std::vector<sf::IntRect>>);
    void nextAnimation(void);
    
    void handKeys(void);
};