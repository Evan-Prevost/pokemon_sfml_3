#pragma once

#include "AnimatedMainCharacter.h"

AnimatedMainCharacter::AnimatedMainCharacter(const sf::Texture& texture, std::vector<sf::IntRect> animation_pos) : Entity(texture)
{
    this->_count = 0;
    this->_animation_pos = animation_pos;

    if (animation_pos.size() <= 0)
        throw;

    this->_sprite.setTextureRect(this->_animation_pos[this->_count]);
}

void AnimatedMainCharacter::nextAnimation(void)
{
    this->_count++;

    if (this->_count >= this->_animation_pos.size())
        this->_count = 0;

    this->_sprite.setTextureRect(_animation_pos[this->_count]);
}