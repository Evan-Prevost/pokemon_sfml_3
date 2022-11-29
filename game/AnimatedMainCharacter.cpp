#pragma once

#include "AnimatedMainCharacter.h"

AnimatedMainCharacter::AnimatedMainCharacter(const sf::Texture& texture, std::vector<std::vector<sf::IntRect>> animation_pos) : Entity(texture)
{
    this->_count = 0;
    this->_animation_pos = animation_pos;

    if (animation_pos.size() <= 0)
        throw;

    this->_sprite.setTextureRect(this->_animation_pos[this->_count][this->currentAnimation]);
}

void AnimatedMainCharacter::nextAnimation(void)
{
   this->currentAnimation++;

   if (this->currentAnimation >= this->_animation_pos.size())
   {
       this->currentAnimation = 0;
   }

    this->_sprite.setTextureRect(_animation_pos[this->_count][this->currentAnimation]);
}

void AnimatedMainCharacter::handKeys(void)
{
    // UP
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        this->_sprite.move(0, -m_speed);
        this->_count = 3;
    }
    // DOWN
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->_sprite.move(0, m_speed);
        this->_count = 1;
    }
    // LEFT
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->_sprite.move(-m_speed, 0);
        this->_count = 2;
    }
    // RIGHT
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->_sprite.move(m_speed, 0);
        this->_count = 0;
    }
}