#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
protected:
    sf::Sprite _sprite;
    const sf::Texture& _texture;

    float m_speed = 1.0f;

    //bool m_movingRight = false;
    //bool m_movingLeft = false;
    //bool m_movingUp = false;
    //bool m_movingDown = false;

public:
    Entity(const sf::Texture& texture);

    //
    sf::Sprite& getSprite(void);
    const sf::Sprite& getSprite(void) const;

    void handKeys(void);
    //
    void setPosition(float x, float y);

    //void goLeft();
    //void stopLeft();

    //void goRight();
    //void stopRight();

    //void goUp();
    //void stopUp();

    //void goDown();
    //void stopDown();

    //void update();
};