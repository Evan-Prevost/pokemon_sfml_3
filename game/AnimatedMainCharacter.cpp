#pragma once

#include "AnimatedMainCharacter.h"

AnimatedMainCharacter::AnimatedMainCharacter(const sf::Texture& texture, std::vector<std::vector<sf::IntRect>> animation_pos) : Entity(texture), boxCollision(sf::Vector2f(12.f, 8.f))
{
    this->_count = 0;
    this->_animation_pos = animation_pos;

    if (animation_pos.size() <= 0)
        throw;

    this->_sprite.setTextureRect(this->_animation_pos[this->_count][this->currentAnimation]);

    // uncomment to see box collision 
    this->boxCollision.setFillColor(sf::Color(0, 0, 0, 50));
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

void AnimatedMainCharacter::handKeys(sf::View& view)
{
    // UP
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        //deplacement sprite
        this->_sprite.move(0, -m_unitDeplacement);
        this->_count = 3;
        view.move(0, -m_unitDeplacement);
        //deplacement box collision
        this->boxCollision.move(0, -m_unitDeplacement);
    }
    // DOWN
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->_sprite.move(0, m_unitDeplacement);
        this->_count = 1;
        view.move(0, m_unitDeplacement);
        //deplacement box collision
        this->boxCollision.move(0, m_unitDeplacement);
    }
    // LEFT
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->_sprite.move(-m_unitDeplacement, 0);
        this->_count = 2;
        view.move(-m_unitDeplacement, 0);
        //deplacement box collision
        this->boxCollision.move(-m_unitDeplacement, 0);
    }
    // RIGHT
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->_sprite.move(m_unitDeplacement, 0);
        this->_count = 0;
        view.move(m_unitDeplacement, 0);
        //deplacement box collision
        this->boxCollision.move(m_unitDeplacement, 0);
    }
}

void AnimatedMainCharacter::setPositionBoxCollider(float x, float y)
{
    this->boxCollision.setPosition(x, y);
}

const sf::RectangleShape& AnimatedMainCharacter::getBoxCollision() const
{
    return this->boxCollision;
}