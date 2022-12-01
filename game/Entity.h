#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
protected:
    sf::Sprite _sprite;
    const sf::Texture& _texture;

public:
    Entity(const sf::Texture& texture);

    //
    sf::Sprite& getSprite(void);
    const sf::Sprite& getSprite(void) const;
    //
    void setPosition(float x, float y);
    //sf::Vector2f GetPosition() { return _sprite.getPosition(); }

    void setScale(float x, float y);
};