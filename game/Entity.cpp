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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
       this->_sprite.move(0.f, -1.f);
    }   
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->_sprite.move(0.f, 1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->_sprite.move(-1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->_sprite.move(1.f, 0.f);
    }
}