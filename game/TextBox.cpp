#include "TextBox.h"


TextBox::TextBox() : Entity() {

}

TextBox::TextBox(const sf::Texture& texture, const sf::Font& font, std::string string) : Entity(texture) {
    this->_text.setScale(0.1, 0.1);
    this->_text.setCharacterSize(150);
    
    this->_font = font;
    this->_text.setFont(this->_font);
    this->_text.setString(string);
}


const sf::Text& TextBox::getText() const {
    return this->_text;
}

void TextBox::setText(std::string string) {
    this->_text.setString(string);
}

void TextBox::setPosition(float x, float y)
{
    Entity::setPosition(x, y);
    this->_text.setPosition(x+5, y+5);
}


