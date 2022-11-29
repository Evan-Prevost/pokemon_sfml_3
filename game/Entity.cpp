#include "Entity.h"

Entity::Entity(const sf::Texture& texture) : _sprite(texture), _texture(texture)
{
}

sf::Sprite& Entity::getSprite(void)
{
    return this->_sprite;
}

const sf::Sprite& Entity::getSprite(void) const
{
    return this->_sprite;
}

void Entity::setPosition(float x, float y)
{
    this->_sprite.setPosition(x, y);
}

void Entity::handKeys(void)
{
    // UP
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
       this->_sprite.move(0, -m_speed);
    }
    // DOWN
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->_sprite.move(0, m_speed);
    }
    // LEFT
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->_sprite.move(-m_speed, 0);
    }
    // RIGHT
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->_sprite.move(m_speed, 0);
    }
}

void Entity::setScale(float x, float y) {
    this->_sprite.setScale(x, y);
}