#pragma once

#include "Entity.h"

class AnimatedMainCharacter : public Entity
{
protected:
    size_t _count;
    std::vector<sf::IntRect> _animation_pos;

public:
    AnimatedMainCharacter(const sf::Texture&, std::vector<sf::IntRect>);
    void nextAnimation(void);
};