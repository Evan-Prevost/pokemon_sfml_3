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
       this->_sprite.move(0, -m_speed);
    }   
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->_sprite.move(0, m_speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->_sprite.move(-m_speed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->_sprite.move(m_speed, 0);
    }
}

//void Entity::goLeft() {
//    m_movingLeft = true;
//}
//
//void Entity::goRight() {
//    m_movingRight = true;
//}
//
//void Entity::stopLeft() {
//    m_movingLeft = false;
//}
//
//void Entity::stopRight() {
//    m_movingRight = false;
//}
//
//void Entity::goUp() {
//    m_movingUp = true;
//}
//
//void Entity::stopUp() {
//    m_movingUp = false;
//}
//
//void Entity::goDown() {
//    m_movingDown = true;
//}
//
//void Entity::stopDown() {
//    m_movingDown = false;
//}

//void Entity::update() {
//	if (m_movingLeft) {
//		if ((m_sprite.getPosition().x - (m_texture.getSize().x / 2) > 0)) {
//			m_position.x -= m_speed * t.asSeconds();
//		}
//		else {
//			m_movingLeft = false;
//		}
//	}
//	else if (m_movingRight) {
//		if (m_sprite.getPosition().x + (m_texture.getSize().x / 2) < windowSize.x) {
//			m_position.x += m_speed * t.asSeconds();
//		}
//		else {
//			m_movingRight = false;
//		}
//	}
//	else if (m_movingUp) {
//		if ((m_sprite.getPosition().y - (m_texture.getSize().y / 2) > 0)) {
//			m_position.y -= m_speed * t.asSeconds();
//		}
//		else {
//			m_movingDown = false;
//		}
//	}
//	else if (m_movingDown) {
//		if (m_sprite.getPosition().y + (m_texture.getSize().y / 2) < windowSize.y) {
//			m_position.y += m_speed * t.asSeconds();
//		}
//		else {
//			m_movingUp = false;
//		}
//	}
//	m_sprite.setPosition(m_position);
//}