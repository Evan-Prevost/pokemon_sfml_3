#include "Entity.h"

Entity::Entity(){
    sf::Texture texture;
    this->_sprite.setTexture(texture);
}

Entity::Entity(const sf::Texture& texture) : _sprite(texture)
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

void Entity::setScale(float x, float y) {
    this->_sprite.setScale(x, y);
}