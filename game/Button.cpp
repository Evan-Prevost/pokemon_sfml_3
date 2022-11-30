#include "Button.h"

Button::Button(const sf::Texture& texture, const sf::Font& font, std::string string) : TextBox(texture, font, string) {
    this->_text.setScale(0.1, 0.1);
    this->_text.setCharacterSize(150);
    
}

void Button::setPosition(float x, float y)
{
    Entity::setPosition(x, y);
    //sf::Vector2u size = this->_sprite.getTexture()->getSize();
    //this->_text.setPosition(x+size/2-  , y);
    this->_text.setPosition(x+20, y+5.5);
}