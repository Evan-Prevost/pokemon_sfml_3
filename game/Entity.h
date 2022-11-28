#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
protected:
    sf::Sprite _sprite;
    const sf::Texture& _texture;

    // speed main character
    float m_speed = 1.0f;

public:
    Entity(const sf::Texture& texture);

    //
    sf::Sprite& getSprite(void);
    const sf::Sprite& getSprite(void) const;

    void handKeys(void);
    //
    void setPosition(float x, float y);

    sf::Vector2f GetPosition() { return _sprite.getPosition(); }
};