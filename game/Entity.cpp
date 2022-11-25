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